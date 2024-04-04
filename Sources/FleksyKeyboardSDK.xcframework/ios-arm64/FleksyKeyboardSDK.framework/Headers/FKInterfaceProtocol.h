//
//  FKInterface.h
//  FleksyKeyboardSDK
//
//  Created by Antonio J Pallares on 17/1/22.
//  Copyright © 2022 Thingthing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FKInterfaceDelegate.h"
#import "FKEnums.h"
#import "KeyboardConfigurationTypes.h"
#import "FleksyThemeableUI.h"

NS_ASSUME_NONNULL_BEGIN

@protocol FKInterfaceProtocol <NSObject>


- (NSUInteger)keyboardID OBJC_UNAVAILABLE("This method can't be used and will be removed in a future release of the SDK.\n\nIf you rely on this method and do not know how to work around it not being available anymore, please contact the Fleksy team");
- (void)setKeyboardID:(NSUInteger)keyboardID OBJC_UNAVAILABLE("This method can't be used and will be removed in a future release of the SDK.\n\nIf you rely on this method and do not know how to work around it not being available anymore, please contact the Fleksy team");

/// Use this method to change the delegate of the Interface.
/// @param interfaceDelegate The new delagate for the Interface.
///
/// By default, your @c FKKeyboardViewController subclass is the delegate (note that @c FKKeyboardViewController implements the @c FKInterfaceDelegate protocol).
- (void)setInterfaceDelegate:(NSObject<FKInterfaceDelegate> *)interfaceDelegate;

- (void) insertText:(NSString*) text;
- (void) replaceText:(NSString*) text inRange:(NSRange) range;
- (void) replaceAllTextWith:(NSString*) text;
- (void) deleteBackward;
- (void) deleteBackwardWord;


- (void)insertWordPrediction:(NSString *)prediction
                     withType:(WordPredictionType)type;

- (void) updateFlaggedWordsFile:(NSString*)filePath
                    forLanguage:(NSString*) language;

// This method is not going to be maintained, move to loadCollectionActions
- (void) enableCollectionActions:(BOOL) value
                  collectionText:(BOOL) text __deprecated;

- (void)loadCollectionActions:(CaptureConfiguration * __nonnull)capture __deprecated_msg("Use FKKeyboardViewController's reloadConfiguration to change data capture configuration instead");
- (void) enableEncryptionWithKey:(NSString*) key;

- (void) subscribeEventBus:(NSArray<NSString *>*) arrayEvents;

- (UIView * _Nullable) getPanelCustomTopbarView;

- (BOOL) reloadTheme:(NSDictionary*) theme;

- (BOOL) changeLanguageTo:(NSString *)languageCode layout:(NSString*) layout;

- (void) updateKeyboardInsets:(UIEdgeInsets) insets;

// User Dictionary management
- (void) addWordUserDictionary:(NSString*) word;
- (NSArray<NSString *>* _Nonnull) listWordUserDictionary;
- (void) removeWordUserDictionary:(NSString*) word;
- (void) removeAllWordsUserDictionary;

// AutoLearn: delete the current learnings
- (void) deleteAutolearnDictionary;

// Reload Settings
- (void) reloadSettings;

// Reload Dynamic Configuration
- (void) reloadDynamicConfiguration:(KeyboardDynamicConfiguration*) configuration;

/// Add extra data to collected data for the current session.
///
/// - Important: This method is only supported for session-based data capture.
/// The calls to this method when event-based data capture is enabled are ignored.
- (void) addCustomCollectedData:(NSDictionary*) dict;

/// DEBUG: Restarts the typing session.
///
/// As a result, this triggers all events at the end of a session.
/// This is intended to be used for Testing purposes and
/// this will be the new method instead of flushCollectedData
- (void) flushCollectedData __deprecated_msg("Use debugFlushRestartTypingSession instead");

/// DEBUG: Restarts the typing session.
///
/// As a result, this triggers all events at the end of a session.
/// This is intended to be used for Testing purposes and
/// this will be the new method instead of flushCollectedData
- (void) debugFlushRestartTypingSession;

// DEBUG: This will help debugging the system to inject points
// that will be translated to keys, actions
- (void) debugSendPoint:(CGPoint)point endPoint:(CGPoint) endPoint diff:(NSTimeInterval)time;
- (void) debugSendPrediction:(CGPoint)point endPoint:(CGPoint) endPoint diff:(NSTimeInterval)time;

// License
/// Use this readonly property to get the current status of the SDK license. To know what capabilities of the SDK are enabled, check @c capabilities.
///
/// If you're using Swift, use the @c activationStatus property in @c FKKeyboardViewController.
@property (nonatomic, readonly) NSInteger activationStatus;

/// Use this readonly property to get the current enabled capabilities of the SDK. The @c NSSet contains @c NSNumber elements where the wrapped values are the integers of the @c FKKeyboardLicenseCapability enum.
///
/// Note that the capabilities are given by the type of the license of the SDK. In addition, in order for them to be available, the license needs to be validated. Specifically, if the license cannot be validated, then the current capabilities will be empty. See `activationStatus`,
///
/// If you're using Swift, better use the @c activationStatus property in @c FKKeyboardViewController.
@property (nonatomic, readonly) NSSet<NSNumber *> *licenseCapabilities;

@end

/**
 *  Data Collection protocol to implement in order to receive calls
 *  when we upload the data.
 *  Create an object extending this one and pass it via viewWillDissappearWithDataCollection(...)
 */
@protocol FKDataCollection <NSObject>

- (void) dataCollection:(NSString*) data;
- (void) dataCollectionFormatDict:(NSDictionary*) data;

@end

/**
 *  Interface to be implemented to receive any of these calls as a protocol
 */
@protocol FKInterfaceInputViewControllerDelegate <NSObject, FKInterfaceDelegate>

- (void) addKeyboardViewController:(UIViewController *) currentKeyboardVC;
- (void) addDisplayedViewController:(UIViewController<FleksyThemeableUI> *) displayVC;
- (void) addExtensionsViewController:(UIViewController*) extensionsVC;

- (void) dismissKeyboardButton;
- (void) changeKeyboardButton;

- (void)onKeyboardFrameChanged;

// Top bar customization

@property (readonly) UIImage * _Nullable appIcon;
@property (readonly) UIView * _Nullable leadingTopBarView;
@property (readonly) UIView * _Nullable trailingTopBarView;

@end

NS_ASSUME_NONNULL_END
