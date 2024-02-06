import 'dart:io';
import 'dart:typed_data';
import 'package:flutter/material.dart';
import 'package:nfc_manager/nfc_manager.dart';

/// Global flag if NFC is avalible
bool isNfcAvalible = false;

void main() async {
  WidgetsFlutterBinding.ensureInitialized(); // Required for the line below
  isNfcAvalible = await NfcManager.instance.isAvailable();
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter NFC Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePage(title: 'Flutter NFC Demo'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});
  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  int _counter = 0;
  // final result = Null;
  String? r, r1;
  bool listenerRunning = false;
  bool writeCounterOnNextContact = false;

  void _incrementCounter() {
    setState(() {
      _counter++;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            const Text(
              'You have pushed the button this many times:',
            ),
            Text(
              '$_counter',
              style: Theme.of(context).textTheme.headline4,
            ),
            const Text(
              'Your Response in bytes:',
            ),
            Text(
              '$r1',
              style: Theme.of(context).textTheme.headline4,
            ),
            const Text(
              'Your Responsein Hex:',
            ),
            Text(
              '$r',
              style: Theme.of(context).textTheme.headline4,
            ),
            _getNfcWidgets(),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _incrementCounter,
        tooltip: 'Increment',
        child: const Icon(Icons.add),
      ),
    );
  }

  Widget _getNfcWidgets() {
    if (isNfcAvalible) {
      //For ios always false, for android true if running
      final nfcRunning = Platform.isAndroid && listenerRunning;
      return Row(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          TextButton(
            onPressed: nfcRunning ? null : _listenForNFCEvents,
            child: Text(Platform.isAndroid
                ? listenerRunning
                    ? 'NFC is running'
                    : 'Start NFC listener'
                : 'Read from tag'),
          ),
          TextButton(
            onPressed: writeCounterOnNextContact ? null : _writeNfcTag,
            child: Text(writeCounterOnNextContact
                ? 'Waiting for tag to write'
                : 'Write to tag'),
          ),
          TextButton(
              onPressed: () => setState(() {
                    _counter = 0;
                  }),
              child: const Text('Reset counter'))
        ],
      );
    } else {
      if (Platform.isIOS) {
        //Ios doesnt allow the user to turn of NFC at all,  if its not avalible it means its not build in
        return const Text("Your device doesn't support NFC");
      } else {
        //Android phones can turn of NFC in the settings
        return const Text(
            "Your device doesn't support NFC or it's turned off in the system settings");
      }
    }
  }

  //Helper method to show a quick message
  void _alert(String message) {
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(
        content: Text(
          message,
        ),
        duration: const Duration(
          seconds: 2,
        ),
      ),
    );
  }

  Future<void> _listenForNFCEvents() async {
    //Always run this for ios but only once for android
    if (Platform.isAndroid && listenerRunning == false || Platform.isIOS) {
      //Android supports reading nfc in the background, starting it one time is all we need
      if (Platform.isAndroid) {
        _alert(
          'NFC listener running in background now, approach tag(s)',
        );
        //Update button states
        setState(() {
          listenerRunning = true;
        });
      }

      NfcManager.instance.startSession(
        onDiscovered: (NfcTag tag) async {
          bool succses = false;
          //Try to convert the raw tag data to NDEF
          // r = Ndef.from(tag).toString();
          final ndefTag = Ndef.from(tag);
          //If the data could be converted we will get an object
          if (ndefTag != null) {
            try {
              var ndefMessage = ndefTag.cachedMessage!;
              final wellKnownRecord = ndefMessage.records.first;
              final languageCodeAndContentBytes =
                  wellKnownRecord.payload.toList();
              // final languageCodeAndContentText =
              //     utf8.decode(languageCodeAndContentBytes);
              // final payload = languageCodeAndContentText.substring(2);
              r = languageCodeAndContentBytes
                  .map((int byte) => byte.toRadixString(16).padLeft(2, '0'))
                  .join(' ');
              r1 = languageCodeAndContentBytes.toString();
              //   var ndefMessage = ndefTag.cachedMessage!;
              //   final result = ndefMessage.records.first;
              //   r = result;
              succses = true;
            } catch (e) {
              _alert('Error reading NdefMessage:$e');
            }
            // If we want to write the current counter vlaue we will replace the current content on the tag
            if (writeCounterOnNextContact) {
              //Ensure the write flag is off again
              setState(() {
                writeCounterOnNextContact = false;
              });
              //Create a 1Well known tag with en as language code and 0x02 encoding for UTF8
              Uint8List uint8Array =
                  Uint8List.fromList([0x70 + _counter, 0x00]);
              String type = "application/octet-stream";
              final ndefRecord = NdefRecord.createMime(type, uint8Array);
              // final ndefRecord = NdefRecord.createText(_counter.toString());
              //Create a new ndef message with a single record
              final ndefMessage = NdefMessage([ndefRecord]);
              //Write it to the tag, tag must still be "connected" to the device
              try {
                //Any existing content will be overrwirten
                await ndefTag.write(ndefMessage);
                _alert('Counter written to tag');
                succses = true;
              } catch (e) {
                _alert("Writting failed, press 'Write to tag' again");
              }
            }

            // //The NDEF Message was already parsed, if any
            // if (ndefTag.cachedMessage != null) {
            // var ndefMessage = ndefTag.cachedMessage!;
            //   //Each NDEF message can have multiple records, we will use the first one in our example
            //   if (ndefMessage.records.isNotEmpty &&
            //       ndefMessage.records.first.typeNameFormat ==
            //           NdefTypeNameFormat.nfcWellknown) {
            //     //If the first record exists as 1:Well-Known we consider this tag as having a value for us
            // final wellKnownRecord = ndefMessage.records.first;

            //     ///Payload for a 1:Well Known text has the following format:
            //     ///[Encoding flag 0x02 is UTF8][ISO language code like en][content]

            //     if (wellKnownRecord.payload.first == 0x02) {
            //       //Now we know the encoding is UTF8 and we can skip the first byte
            // final languageCodeAndContentBytes =
            //     wellKnownRecord.payload.skip(1).toList();
            //       //Note that the language code can be encoded in ASCI, if you need it be carfully with the endoding
            // final languageCodeAndContentText =
            //     utf8.decode(languageCodeAndContentBytes);
            //       //Cutting of the language code
            // final payload = languageCodeAndContentText.substring(2);
            // r = payload;
            //       //Parsing the content to int
            //       final storedCounters = int.tryParse(payload);
            //       if (storedCounters != null) {
            //         succses = true;
            //         _alert('Counter restored from tag');
            //         setState(() {
            //           _counter = storedCounters;
            //         });
            //       }
            //     }
            //   }
            // }
          }
          //Due to the way ios handles nfc we need to stop after each tag
          if (Platform.isIOS) {
            NfcManager.instance.stopSession();
          }
          if (succses == false) {
            _alert(
              'Tag was not valid',
            );
          }
        },
        // Required for iOS to define what type of tags should be noticed
        pollingOptions: {
          NfcPollingOption.iso14443,
          NfcPollingOption.iso15693,
        },
      );
    }
  }

  @override
  void dispose() {
    try {
      NfcManager.instance.stopSession();
    } catch (_) {
      //We dont care
    }
    super.dispose();
  }

  void _writeNfcTag() {
    setState(() {
      writeCounterOnNextContact = true;
    });

    if (Platform.isAndroid) {
      _alert('Approach phone with tag');
    }
    //Writing a requires to read the tag first, on android this call might do nothing as the listner is already running
    _listenForNFCEvents();
  }
}
