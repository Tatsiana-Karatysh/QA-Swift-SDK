//
//  FleksyKeyboardSDK.h
//  FleksyKeyboardSDK
//
//  Created by Xevi on 01/07/2019.
//  Copyright © 2019 Thingthing.Ltd All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for FleksyKeyboardSDK.
FOUNDATION_EXPORT double FleksyKeyboardSDKVersionNumber;

//! Project version string for FleksyKeyboardSDK.
FOUNDATION_EXPORT const unsigned char FleksyKeyboardSDKVersionString[];

#import "FKKeyboardViewController.h"
#import "FKInterfaceProtocol.h"
#import "FKInterfaceDelegate.h"
#import "FleksyUtility.h"
#import "FleksyUtility+ControlOpenURLs.h"
#import "FKStatsFileManager.h"
#import "KeyboardConfigurationTypes.h"
#import "FleksyDefines.h"
#import "FleksyExtensionSetupStatus.h"
#import "FKEnums.h"
#import "FleksyTheme.h"
#import "FleksyThemeableUI.h"
#import "FleksyDebugSDK.h"
#import "AppearancePopup.h"
#import "PerformanceDelegate.h"
#import "FleksyViewControllerPresenter.h" // Needs to be public because of Swift
#import "FleksyCursorControllable.h" // Needs to be public because of Swift
#import "FlickDirection.h" // Needs to be public because it was part of old, deprecated `AppearancePopup` API
#import "FleksyAPIManagerDelegate.h" // Needs to be public because of Swift
#import "FleksyKeyboardDisplayStateInfoProvider.h" // Needs to be public because of Swift
#import "FleksyJapaneseKeyboardStatusProvider.h" // Needs to be public because of Swift
#import "FleksyInternalDefines.h" // Needs to be public because of Swift
#import "FleksyTouchIdentifierDelegate.h" // Needs to be public because of Swift
#import "FleksyKeyPadViewDelegate.h" // Needs to be public because of Swift
#import "FleksyFontProvider.h" // Needs to be public because of Swift
#import "FleksyPullDownViewController.h" // Needs to be public because of Swift

