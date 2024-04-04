//
//  FKInterfaceDelegate.h
//  FleksyKeyboardSDK
//
//  Created by Antonio J Pallares on 18/1/22.
//  Copyright © 2022 Thingthing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FKEnums.h"

NS_ASSUME_NONNULL_BEGIN

@class FKAppsGenericViewController;
@class FKAppsObject;
@protocol FKAppsGenericInteractionProtocol;

/// Methods to receive keyboard data collection and events.
@protocol FKInterfaceDelegate <NSObject>

@optional

/// Called when a notification is triggered by the SDK. Only called for notifrications to which you have subscribed with @c -subscribeEventBus: .
/// @param event The notification name.
/// @param dictPayload A dictionary containing the payload of the notification
- (void)eventBus:(NSString *)event payload:(nullable NSDictionary *)dictPayload;


/// Implement this method to get notified that a new keyboard session started.
/// @param sessionId The ID of the session.
- (void)sessionStarted:(NSString *)sessionId;

/// Implement this method to get notified that an existing keyboard session ended.
/// @param sessionId The ID of the session.
- (void)sessionEnded:(NSString *)sessionId;

/// Implement this method to receive the data captured in form of string with its associated session ID.
///
/// @param data The data captured in form of string.
/// @param sessionId The session ID associated to the data captured.
- (void)dataCollection:(NSString *)data sessionId:(NSString *)sessionId;

/// Implement this method to receive the data captured in form of string.
///
/// @param data The data captured in form of string.
- (void)dataCollection:(NSString *)data __deprecated_msg("Use method dataCollection:sessionId instead");

/// Implement this method to receive the data captured in dictionary form.
///
/// @param data The data captured in form of string.
/// @param sessionId The session ID associated to the data captured.
- (void)dataCollectionFormatDict:(NSDictionary *)data sessionId:(NSString *)sessionId;

/// Implement this method to receive the data captured in dictionary form.
///
/// @param data The data captured in form of string.
- (void)dataCollectionFormatDict:(NSDictionary *)data __deprecated_msg("Use method dataCollectionFormatDict:sessionId instead");

/// Implement this method to get notified that the data captured for a session has been stored into a file.
///
/// @param path The path of the file where the data captured has been stored.
/// @param sessionId The session ID associated to the data captured.
- (void)dataCollectionStored:(NSString *)path sessionId:(NSString *)sessionId;

/// Report Analytics is accumulative, which means that accumulates all statistics for you,
- (void)reportAnalytics:(NSDictionary *)data;

/// Report Layout changes
- (void)onLayoutChanges:(NSDictionary *)dictLayout;

- (void)updateKeyboardAppsTextDocumentProxy:(nullable id<UITextDocumentProxy>)documentProxy;

- (nullable FKAppsGenericViewController*) customKeyboadApp:(FKAppsObject*) object
                                     withDelegate:(id<FKAppsGenericInteractionProtocol>) delegate;

/// Implement this method if you want to get all
/// updates of the KeyboardProperties changes.
- (void)contextPropertiesChanged:(KeyboardProperties*)properties;

/// Do here anything you want at button press - "magnifier button"
- (void)triggerOpenApp;

@end

NS_ASSUME_NONNULL_END
