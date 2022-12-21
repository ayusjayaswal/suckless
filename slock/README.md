# slock - simple screen locker
simple screen locker utility for X.


## Requirements
In order to build slock you need the Xlib header files.


## Installation
Edit config.mk to match your local setup (slock is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install slock
(if necessary as root):
```
sudo make clean install
```
## Setup
Edit config.h file and put your user name and user group
```
/* user and group to drop privileges to */
static const char *user  = "<user_name>";
static const char *group = "<user_group";
```

## Running slock

Simply invoke the 'slock' command. To get out of it, enter your password.
```
slock
```
