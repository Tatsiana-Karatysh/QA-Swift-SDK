//  FleksyTouchIdentifierDelegate.h
//  FleksyKeyboardSDK
//
//  Copyright © 2023 Thingthing. All rights reserved.
//

#import <UIKit/UIKit.h>
@class FleksyTouch;

@protocol FleksyTouchIdentifierDelegate <NSObject>

/// The default swipe trigger length threshold. That is the minimum distance for a swipe gesture to be interpreted as a swipe.
@property (assign, nonatomic, readonly) CGFloat swipeTriggerLength;

- (void)handleForceTouchBegan:(CGPoint)point;
- (void)handleForceTouchMoved:(CGPoint)point;
- (void)handleForceTouchEnded:(CGPoint)point;
/**
 Notifies the receiver that a tap was recognized
 */
- (void)handleTap:(CGPoint)point toEndLocation:(CGPoint) endPoint timestampTouch:(NSTimeInterval)time;
/**
 Notifies the receiver that a touch has begun
 */
- (void)handleTapBegan:(CGPoint)point;
/**
 Notifies the receiver that a long press has begun
 */
- (void)handleLongPressBegan:(FleksyTouch *)touch;
/**
 Notifies the receiver that a long press has moved
 */
- (void)handleLongPressMoved:(FleksyTouch *)touch;
/**
 Notfies the recveiver that a long press has ended
 */
- (void)handleLongPressEndedWithTouch:(FleksyTouch *)touch time:(NSTimeInterval)time;
/**
 Notfies the receiver that a swipe was recognized
 @param touch the touch associated with the gesture
 @param isContinuation whether this swipe is part of the same touch event as a prior swipe
 */
- (void)handleSwipe:(FleksyTouch *)touch
     isContinuation:(BOOL)isContinuation;
/**
 Keep moving so we need to notify new positions
 */
- (void)handleContinueMove:(CGPoint)point;

/// Notifies the receiver of a touch point that it needs to save, in case it turns out to be a swipe. This way
/// the full history of the swipe points can be considered.
- (void)savePotentialFutureContinuousMovePoint:(CGPoint)point;
/**
 Notifies the receiver that a tap ended.
 */
- (void)handleTapEnded:(CGPoint)point  toEndLocation:(CGPoint) endPoint timestampTouch:(NSTimeInterval)time;
/**
 Notifies the receiver that a user interaction has ended -- however, no changes to the model should be made as
 a result.
 */
- (void)handleTapEndedCosmetic:(CGPoint)point toEndLocation:(CGPoint) endPoint timestampTouch:(NSTimeInterval)time;

/**
Notifies the receiver that a user interaction has ended -- this will be trigger in case of we don't have an associated @c FleksyTouch . Used for cosmetic and to finish some actions (such as flick swipes).
*/
- (void)handleTapEndedCosmetic:(CGPoint)point timestampTouch:(NSTimeInterval)time;
/**
 Notifies the receiver that touches were canceled
 */
- (void)handleTouchesCancelled;
/**
 Certain points in the keypad may have different fast hold times -- for example, invoking the emoji keyboard is
 faster than a long press on the keypad itself.
 @param point the point to retrieve the fast hold speed from
 @returns the amount of time that is necessary for a long press to be recognized at the point
 */
- (NSTimeInterval)holdSpeedForPoint:(CGPoint)point;

/// Returns whether multiple simultaneous touches should be queued up (@c YES ) or whether any new touch should force any existing touch to be finished
- (BOOL)allowsTouchesBuffering;

/// The swipe type that is allowed to be sent as a continue move (using the method `- (void)handleSwipe:(FleksyTouch *)touch isContinuation:(BOOL)isContinuation` with the `isContinuation` parameter with `true`.
- (FleksyTouchType)swipeTypeToContinue;

/// Returns the extended swipe trigger length threshold based on the start touch point.
///
/// When a user types very fast, some tap gestures can be misinterpreted as swipes. For this reason, after a tap has happened, we increase the swipe trigger distance threshold for the next touch in case it happens very quickly after the previous touch. This method is supposed to return a value greater than `swipeTriggerLength`.
- (CGFloat)extendedSwipeTriggerLenghtForTouchAt:(CGPoint)point;

@end
