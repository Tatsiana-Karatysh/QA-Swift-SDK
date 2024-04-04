//
//  AppearanceLongPress.h
//  FleksyKeyboardSDK
//
//  Created by Xevi on 02/06/2020.
//  Copyright © 2020 Thingthing. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

DEPRECATED_MSG_ATTRIBUTE("AppearanceLongPress API is deprecated and ignored") @interface AppearanceLongPress : NSObject<NSCopying>

/**
 *  Get position of the view respect the 0,0 over the key
 *  CGSizeZero position it's over the same key
 */
- (CGSize) getPosition;

/**
 *  Margin left, right of the popup view
 */
- (CGFloat) getMarginPopupLeft;
- (CGFloat) getMarginPopupRight;

/**
 *  Padding of the key
 */
- (CGFloat) getPaddingKeyX;
- (CGFloat) getPaddingKeyY;

/**
 * Create the path of the shape of the popups at longpress
 */
- (UIBezierPath*) createPath:(CGRect) rect sizeElement:(CGSize) sizeElement position:(NSUInteger) position total:(NSUInteger) total;

/**
 *  Create path of the shape of some of the popups at longpress
 *  // This is a simplified version of the previous createPath, thought it's mandatory to have it implemented
 */
- (UIBezierPath*) createPath:(CGRect) rect sizeElement:(CGSize) sizeElement position:(NSUInteger) multiplier toRight:(BOOL) right;

/// Creates the path of the shape of the Flick keyboard popup at longpress.
/// @param bounds The rect containing all the popup keys for the longpress.
///
/// The implementation of @c AppearanceLongPress returns a cross-shaped path defined by an equally distributed 3x3 grid of @c bounds.
- (UIBezierPath *)createFlickPath:(CGRect)bounds;

@end

NS_ASSUME_NONNULL_END
