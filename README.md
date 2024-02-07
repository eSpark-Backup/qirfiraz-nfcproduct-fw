# qirfiraz-nfcproduct-fw
To develop the firmware of qirfiraz-nfcproduct-fw
## STEPS FOR COMPILING AND FLASHING
### REQUIRED SOFTWARE
[LPC IDE v8.2.2_650](https://nxp.flexnetoperations.com/control/frse/download?agree=Accept&element=7632767)
### Compiling & Flashing Procedure
1. Download the project from here:
[Repository Link](https://github.com/eSpark-Consultants/qirfiraz-nfcproduct-fw/tree/Development)
2. Extract the downloaded folder at a known path in your pc or laptop.
3. Install LPC IDE, open it and navigate to Quickstart Panel and select 'Import Porject' from the left bottom of the IDE.
![](https://github.com/eSpark-Consultants/qirfiraz-nfcproduct-fw/assets/144008938/aa84a8fd-55d5-44b3-bf3f-43a277b410c8)
4. Browse from Project directory(unpacked) as shown below:
![image](https://github.com/eSpark-Consultants/qirfiraz-nfcproduct-fw/assets/144008938/24f78eaa-2c2b-4a58-8043-ee1b021d8fd2)
5. Go to the path where the zip was extracted, and select:                        
![image](https://github.com/eSpark-Consultants/qirfiraz-nfcproduct-fw/assets/144008938/a8ceb29f-c78e-460e-a815-004b995f3d4a)
6. Then select OK, then finish.
7. Build the project through:
![image](https://github.com/eSpark-Consultants/qirfiraz-nfcproduct-fw/assets/144008938/79c45dab-946e-4448-b285-16e94a562c61)
8. Flash the project through: (Make sure your LPC-Link is configured correctly as per the requirement)
![image](https://github.com/eSpark-Consultants/qirfiraz-nfcproduct-fw/assets/144008938/27f672a6-8381-4dc5-a67c-2ac95056a5d1)
### Important Note
Do check your COM Ports, it should give:
![image](https://github.com/eSpark-Consultants/qirfiraz-nfcproduct-fw/assets/144008938/ad0b7b93-2cd7-42f7-8de7-cf58440893f5)
## STEPS FOR MOBILE APPLICATION
Downlaod and install the apk on your mobile having nfc functionality from the given link below.
[APK Link](https://github.com/eSpark-Consultants/qirfiraz-nfcproduct-fw/blob/Development/Mobile%20Application/nfc_counter_apk/app-release.apk)
## WORKING MECHANISM
1. Open the app, there is a button at the right bottom that is responsible for incrementing the counter value.
2. If the counter is 0, it means it is having value 0x70.
3. Click on 'write tag' button and place your mobile on the nfc tag, 'Counter written' will be shown which deduces that the tag has been written to the nfc tag.
4. The app will read the nfc tag just after writing to it. If the app doesn't read the tag and the response isn't shown on the app, it means the command hasn't been written to the nfc tag. So repeat the steps from point 3.
