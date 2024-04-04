//
//  FKKeyboardViewController.h
//  FleksyKeyboardSDK
//
//  Created by Antonio J Pallares on 17/1/22.
//  Copyright © 2022 Thingthing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KeyboardProperties.h"
#import "FKInterfaceProtocol.h"
#import "FKInterfaceDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class FKAppsGenericViewController;
@class FKAppsObject;
@class KeyboardConfiguration;
@protocol FKAppsGenericInteractionProtocol;

// Because a Swift class cannot be subclassed in Objective-C,
// this class exists only to allow the integration of the SDK in Objective-C
// (by subclassing *this* FKKeyboardViewController).
//
// If we delete this, then we'll be effectively forcing the integration of our SDK in Swift
// (by subclassing Swift's FKKeyboardViewController).

NS_SWIFT_UNAVAILABLE("Use Swift's FKKeyboardViewController")
@interface FKKeyboardViewController : UIInputViewController<FKInterfaceDelegate>

@property (strong, nonatomic, readonly) NSObject<FKInterfaceProtocol> *interface;

#pragma mark - Required methods to override

/// Returns the configuration for the keyboard.
///
/// - This method must be overriden by subclasses to return a configuration containing, in particular, a valid @c LicenseConfiguration  object.
/// Do not call super's implementation. Doing that will throw an exception.
/// - This method gets invoked as soon as @c -viewDidLoad is invoked. Initialize any dependency needed by this method in @c -viewDidLoad before calling @c super 's implementation .
- (nonnull KeyboardConfiguration *)createConfiguration;

@end

NS_ASSUME_NONNULL_END
