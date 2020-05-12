# Generate a Glimpse Build Environment
This folder contains helper tools that can build the Glimpse source code without affecting your normal working environment.

## Install Vagrant and Oracle VM Virtualbox

* Follow the Vagrant installation instructions here: https://www.vagrantup.com/
* Follow the Oracle VM Virtualbox installation instructions here: https://www.virtualbox.org/

Ensure you installed the "Guest Additions" for Oracle VM Virtualbox, otherwise not all of the `vagrant` functionality will work.

If you are using Windows, you should also install Xming: https://sourceforge.net/projects/xming/

## Using Vagrant
Simply follow the instructions we have documented in the `HACKING` file included with the Glimpse source code. If you are using Windows, you may need to run `export DISPLAY=:0` in your shell for X11 forwarding to work.

**Please note**: The bash scripts provided in this folder are only intended for use inside the virtual machine.
