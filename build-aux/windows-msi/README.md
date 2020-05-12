# Glimpse Image Editor Windows Installer
This bespoke Windows installer is built on [the WiX Toolset](https://wixtoolset.org/).

## Limitations
Currently we only support 32-bit Windows builds of Glimpse Image Editor. We expect to support 64-bit Windows builds in a future release.

Also while we do bundle the dependencies for Python, Glimpse 0.1.0 was released without support for Python plugins. This was because of an upstream documentation bug that had no workaround.

This manifest was made for [WiX Toolset 3.11.2](https://github.com/wixtoolset/wix3/releases/tag/wix3112rtm). We have tried to avoid relying on default values where possible, but your mileage may vary with newer versions.

Finally, if you redistribute your MSI it will trigger [Windows SmartScreen](https://support.microsoft.com/en-us/help/17443/windows-internet-explorer-smartscreen-faq) and anti-virus programs on other peoples' computers. That is because your MSI file [has not been signed](https://wixtoolset.org/documentation/manual/v3/overview/insignia.html). You can theoretically self-sign for development and testing purposes, but you need a [CA validated certificate](https://docs.microsoft.com/en-us/windows-hardware/drivers/dashboard/get-a-code-signing-certificate) for production use.

## How to package Glimpse for Windows
These instructions will package the code as a 32-bit Windows MSI installer. To build the code first, follow the directions provided in the `HACKING` file.

1. Install the WiX toolset and ensure the `%WIX%` environment variable has been set.
2. Create a folder in this directory called `InputFiles32`
3. Copy the contents of your 32-bit build folder to `InputFiles32`
4. Copy the `LICENSE` file to `InputFiles32\LICENSE.TXT\
5. Copy the contents of `C:\msys64\mingw32` to `InputFiles32`
6. Replace every `Guid="YOUR-GUID-HERE"` with your own GUID values
7. Navigate to the directory this file is in using a command prompt window and run the following commands:

```bat
"%WIX%bin"\candle.exe Glimpse32.wxs
"%WIX%bin"\light.exe Glimpse32.wixobj
```
The component versions in `Glimpse32.wxs` may differ from your own, so you will need to update those appropriately. 

You will be pleased to know that we do not include the whole of MinGW inside the MSI file! The WiX build tools just pick out the dependencies we have determined that Glimpse needs to function through a combination of experimentation and guesswork.

## Testing your Glimpse installer
From a command prompt in the same directory as this file, you can test your MSI installer with logging enabled. The first line works for most cases, but you may want to use the second line if you need more verbose output:

```bat
msiexec /i Glimpse32.msi /l* Glimpse32.log
msiexec /i Glimpse32.msi /l*v Glimpse32.log
```

To uninstall Glimpse Image Editor without having to go through the "Add/Remove Programs" control panel area:

```bat
msiexec /x Glimpse32.msi
```
