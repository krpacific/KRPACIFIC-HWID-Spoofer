# krpacificspoofer
KRPacific Spoofer is an open-source hardware ID spoofer designed to bypass game bans by modifying system identifiers. This spoofer was paid, now made open-source.

- Supports both temporary and permanent spoofing
- Works for Fortnite and Valorant (Both tested) - Other games most likely possible as well

Features
1. HWID Spoofing – Changes hardware identifiers to prevent tracking.
2. MAC Address Spoofing – Modifies network adapter addresses.
3. Peripheral ID Spoofing – Alters serials of connected devices.
4. Registry Key Modifications – Adjusts system registry values for bypassing bans.
5. Dual Mode – Supports both temporary (session-based) and permanent (persistent) spoofing.
5. KeyAuth Integration – Allows developers to integrate their own authentication system via KeyAuth.

KeyAuth Features
This project includes built-in support for KeyAuth, possible to add your own authentication system for security and access control.

- Easily integrate KeyAuth API to manage user licenses.
- Prevent unauthorized use of your compiled builds.
- Secure your spoofer with a customizable authentication system.

How to Implement KeyAuth:
1. Sign up at KeyAuth and generate your API credentials.
2. Replace the placeholder credentials in the source code with your own.
3. Compile the project with KeyAuth enabled.

- The file kr.cpp holds your KeyAuth Information (Labelled as 'Paste Here')
- In order to compile this spoofer, please change to your KeyAuth API info -

Building from Source Requirements:
- Windows (Recommended)
- C++ Compiler (MSVC, MinGW, or similar)
- Kernel Driver Signing 
- Admin Privileges for Compilation & Execution


Disclaimer
- This project is provided for educational and research purposes only. Use at your own risk. We do not condone or support cheating, bypassing security measures, or violating game Terms of Service.
- This project was made open-source, with the intention to put it out there purely. Any further actions with this source code are done at your own risk. Support is not provided.
