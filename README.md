# planet-kit-apple
LINE Planet is a cloud-based real-time communications platform as a service (CPaaS) that helps you build a voice and video call environment. With LINE Planet, you can integrate call features into your service at minimum cost.

## Planet Documentation
[LINE Planet Documentation](https://docs.lineplanet.me/) provides additional resources to help you integrate LINE Planet into your service. These resources include LINE Planet specifications, developer guides for each client platform, and server API references.

## Installation

### Requirement
* iOS 12.0 or later
* macOS 10.14.6 or later

### Swift Package Manager

To integrate PlanetKit into your Xcode project using Swift Package Manager, take the following steps:

1. Create a new Xcode project or open an existing Xcode project.
2. Click **File** > **Add Packages...** in the menu bar.
3. Enter the PlanetKit repository URL in the **Search or Enter Package URL** field.
4. If a dialog to authorize access to the repository appears, take the following steps:
    1. If you don’t have a token already, generate a personal access token to access the repository at [https://github.com/settings/tokens/new](https://github.com/settings/tokens/new).
    2. In the dialog, enter your GitHub account and personal access token in **Account** and **Token**.
5. Click the **Add Package** button.

### CocoaPods

[CocoaPods](https://cocoapods.org) is a dependency manager for Swift and Objective-C Cocoa projects. Install CocoaPods with the following command:

```
$ gem install cocoapods
```

To integrate PlanetKit into your Xcode project using CocoaPods, specify it to a target in your `Podfile`:

```
platform :ios, '12.0'
use_frameworks!
 
target 'MyApp' do
  pod 'PlanetKit-SDK-Apple', '~> 5.3', :source => 'https://github.com/line/planet-kit-cocoapods-specs.git'
end
```

Then, run the following command:

```
$ pod install
```

## API Reference
For detailed information on APIs, please refer to the following documents.

* [iOS API Reference](https://docs.lineplanet.me/api-reference/client/ios/5.3/index.html)
* [macOS API Reference](https://docs.lineplanet.me/api-reference/client/macos/5.3/index.html)

## Issues and Inquiries
Please file any issues or inquiries you have to our representative or dl_planet_help@linecorp.com.
Your opinions are always welcome.

## FAQ
You can find answers to our frequently asked questions in the [FAQ](https://docs.lineplanet.me/help/faq/) section.
