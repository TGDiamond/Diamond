Diamond 0.9.99 BETA
=====================

Copyright (c) 2009-2014 Bitcoin Developers


Setup
---------------------
[Diamond Core](http://diacoin.org/en/download) is the original Diamond client and it builds the backbone of the network. However, it downloads and stores the entire history of Diamond transactions (which is currently several GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more. Thankfully you only have to do this once. If you would like the process to go faster you can [download the blockchain directly](bootstrap.md).

Running
---------------------
The following are some helpful notes on how to run Diamond on your native platform. 

### Unix

You need the Qt4 run-time libraries to run Diamond-Qt. On Debian or Ubuntu:

	sudo apt-get install libqtgui4

Unpack the files into a directory and run:

- bin/32/diamond-qt (GUI, 32-dia) or bin/32/diamondd (headless, 32-dia)
- bin/64/diamond-qt (GUI, 64-dia) or bin/64/diamondd (headless, 64-dia)



### Windows

Unpack the files into a directory, and then run diamond-qt.exe.

### OSX

Drag Diamond-Qt to your applications folder, and then run Diamond-Qt.

### Need Help?

* See the documentation at the [Diamond Wiki](https://en.diamond.it/wiki/Main_Page)
for help and more information.
* Ask for help on [#diamond](http://webchat.freenode.net?channels=diamond) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=diamond).
* Ask for help on the [DiamondTalk](https://diamondtalk.org/) forums, in the [Technical Support board](https://diamondtalk.org/index.php?board=4.0).

Building
---------------------
The following are developer notes on how to build Diamond on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OSX Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)

Development
---------------------
The Diamond repo's [root README](https://github.com/diamond/diamond/blob/master/README.md) contains relevant information on the development process and automated testing.

- [Coding Guidelines](coding.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/diamond/doxygen/)
- [Translation Process](translation_process.md)
- [Unit Tests](unit-tests.md)

### Resources
* Discuss on the [DiamondTalk](https://diamondtalk.org/) forums, in the [Development & Technical Discussion board](https://diamondtalk.org/index.php?board=6.0).
* Discuss on [#diamond-dev](http://webchat.freenode.net/?channels=diamond) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=diamond-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)

License
---------------------
Distributed under the [MIT/X11 software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
