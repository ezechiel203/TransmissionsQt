# TransmissionsQt

### Concept
A simple QT5 QtWidget GUI based client side software aimed at creating, editing and sharing informations about patients in a hospital-ward context.
Originally developped in Java + Swing (2012-2013), ported to Qt & C++ in early 2014 because a single binary static build was mandatory (given I was not granted admin rights on the hospital computers, I needed the program to run as-is in userland without dependencies for a deployment as easy as drag-dropping a file from a usb key to the Desktop). This is why **TransmissionsQt** is statically built with a static version of Qt (_5.10 by feb 2018_)

* Created to fit the needs of a Geriatrics Unit in particular (Cours Séjour Gériatrique, CH Tourcoing, France) but can easily be adapted for others
* Can be extended for all types of HealthCare Units
* Uses a per-hospital-bed view both for editing and displaying useful informations
* Quite foolproof (intended users may have a poor knowledge of basic computer-oriented skills)

### Use
Simply run the .exe 
* **TransmissionsQt** first displays a splashscreen on which a QListView enables you to select the sector (Ward, Hallway, Unit, or however you may want to call a collection of hospital beds)
* Main window (TransMain object) is then displayed. 
    * On top, you can see a menu bar you may want to configure. You can either mod this via QTCreator GUI-editor editing transmain.ui, or do it programmatically inside transmain.cpp
    * Below the menu bar, you can see a function bar filled with Icons representing various actions (such as saving XML data to file, printing to default printer, selecting the subset of beds you want to print, or switch patients between beds...). Access to this Function bar is possible within transmain.cpp. You can add, modify or delete some of the actions and replace them by your own customised ones.
    * The main frame of the window represent a QTabWidget in which is displayed a form representing a patient in its bed. Various items are available for edition. This form is an instance of the ChambrePanel.cpp class. You want to edit this file as to edit the form itself. Many of the widgets in it are subclasses of original QtWidgets (in order for example to make the object intelligent enough to check the length of the thext that was imput and react accordingly)
        * Patient name, obviously
        * Date of arrival
        * Several checkboxes indicating current status (oxygen, allergies...)
        * Several text fields, each of which have a label indicating their purpose
    * User can navigate through Tabs with CTRL + right_arrow & CTRL + left_arrow. CTRL + up_arrow switches between sectors (subsets of beds).
* Once the edition phase is complete, you can either
    * print as is
    * print on a custom printer
    * print custom subset of patients
    * preview what will be printed

### Reuse
Feel free to use and reuse this piece of software as-is or modify it to suit your needs.

### Disclaimer
**I am no professionnal programmer. Use this code with caution. You may want to take extra precautions when and if you come to use some of this code in critical security environments.**
