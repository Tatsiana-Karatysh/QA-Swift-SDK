//
//  AppearancePopup.h
//  FleksyKeyboardSDK
//
//  Created by Xevi on 30/05/2020.
//  Copyright © 2020 Thingthing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlickDirection.h"

NS_ASSUME_NONNULL_BEGIN

DEPRECATED_MSG_ATTRIBUTE("AppearancePopup and FLeksyPopLabel APIs are deprecated and ignored")
@interface FleksyPopLabel : UILabel
@end

@class FleksyTheme;

// In the past, integrators would inherit from this class to customise key popups
DEPRECATED_MSG_ATTRIBUTE("AppearancePopup API is deprecated and ignored")
@interface AppearancePopup : NSObject<NSCopying>

/**
 @param bounds CGRect key pressed bounds
 @param letter NSString with the letter pressed
 @param letterFont UIFont with the font to be drawn the letter
 @param theme FleksyTheme with all different parameters
 */
- (UILabel*) popup:(CGRect) bounds
            letter:(NSString*) letter
              font:(UIFont*) letterFont
             theme:(FleksyTheme*) theme __attribute((deprecated("Unused. Returns nil")));

// Overridable methods for customisation
- (UILabel*) createPopup:(CGRect) bounds
                  letter:(NSString*) letter
                    font:(UIFont*) letterFont
                   theme:(FleksyTheme*)theme __attribute((deprecated("Unused. Returns nil")));
- (UILabel*) createPopupLeft:(CGRect) bounds
                      letter:(NSString*) letter
                        font:(UIFont*) letterFont
                       theme:(FleksyTheme*)theme __attribute((deprecated("Unused. Returns nil")));
- (UILabel*) createPopupRight:(CGRect) bounds
                       letter:(NSString*) letter
                         font:(UIFont*) letterFont
                        theme:(FleksyTheme*)theme __attribute((deprecated("Unused. Returns nil")));


/// Creates the view containing the label for the Japanese Flick keyboard key popup that appears on key swipe.
/// @param keyFrame The frame of the key for which to create the popup view.
/// @param direction The direction of the swipe that generates the popup.
/// @param letter The letter to show in the popup.
/// @param keyboardFrame The frame of the parent keyboard view. This frame is relative to the key's superview. This means that it can contain negative coordinates.
/// @param letterFont The font to use in the popup.
/// @param theme The current theme.
///
/// Since a keyboard extension cannot draw outside of its bounds, make sure that the popup view you wish to display is contained within @c keyboardFrame.
- (UIView *)createFlickPop:(CGRect)keyFrame
                 direction:(FlickDirection)direction
                    letter:(NSString*) letter
             keyboardFrame:(CGRect)keyboardFrame
                      font:(UIFont*) letterFont
                     theme:(FleksyTheme*)theme __attribute((deprecated("Unused. Returns nil")));
@end

NS_ASSUME_NONNULL_END
