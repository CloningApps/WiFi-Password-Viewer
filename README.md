
WiFi Password Retriever
WiFi Password Retriever is a lightweight C program designed to display saved WiFi passwords on Linux Debian and Android systems. It provides a simple command-line interface to retrieve and display WiFi network names (SSIDs) and their corresponding passwords.

# Features
Retrieves WiFi passwords from NetworkManager configuration files on Linux Debian systems
Supports Android systems with the --android option
Allows execution without root privileges using the --no-root option (with limited functionality)
Easy to compile and use with the provided Makefile
Installation
Clone this repository:

``git clone https://github.com/CloningApps/WiFi-Password-Viewer.git``
cd wifi-password-retriever
Compile the program using the provided Makefile:

``make``
The compiled binary will be available in the bin directory.

# Usage
Run the program with different options based on your needs:

# For normal operation (requires root):

sudo ./bin/get_wifi_password
For Android mode (requires root):

sudo ./bin/get_wifi_password --android
For no-root mode:

./bin/get_wifi_password --no-root
For Android mode without root:

./bin/get_wifi_password --android --no-root
# Security and Legal Considerations
This program is intended for educational purposes and personal use only.
Only use this program on devices you own or have explicit permission to access.
Accessing or sharing WiFi passwords without permission may be illegal in some jurisdictions.
The ``--no-root`` option may limit the program's ability to access WiFi configuration files.
The ``--android`` option is designed for use on Android devices but may require additional setup or permissions to work correctly.
# System Requirements
Linux Debian-based system or Android device
GCC compiler
Make utility
Contributing
Contributions to improve WiFi Password Retriever are welcome. Please follow these steps to contribute:

# Fork the repository
Create a new branch (git checkout -b feature-branch)
Make your changes and commit them (git commit -am 'Add some feature')
Push to the branch (git push origin feature-branch)
Create a new Pull Request
License
This project is licensed under the MIT License. See the LICENSE file for details.

# Disclaimer
The authors of this software are not responsible for any misuse or legal implications arising from the use of this program. Use at your own risk and always respect privacy and legal boundaries.
