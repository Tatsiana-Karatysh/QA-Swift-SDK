//  FleksyKeyPadViewDelegate.h
//  FleksyKeyboardSDK
//
//  Copyright © 2023 Thingthing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FleksyFontProvider.h"

@class FleksySpeechManager;
@class FleksyLayoutElement;

@protocol FleksyKeyPadViewDelegate <FleksyFontProvider, FleksyJapaneseKeyboardStatusProvider, FleksyKeyboardDisplayStateInfoProvider>

- (NSArray<FleksyLayoutElement *> * _Nullable)getKeyboardLayoutInfoFromEngine;

/// To notify the delegate that the keyboard layout was just set to a new value.
- (void)didSetKeyboardLayout;
- (NSString *)nearestCharacterForPoint:(CGPoint)point;
@property (nonatomic, readonly) BOOL currentInputHasAutocorrect;
@property (nonatomic, readonly) BOOL configurationShowAutocorrectOffIndicator;
@property (nonatomic, readonly) KeyboardID keyboardID;
@property (nonatomic, readonly) KeyboardSize keyboardSize;
@property (nonatomic, readonly) FleksySpeechManager *speechManager;
@property (nonatomic, readonly) BOOL hasMultipleLanguages;
@property (nonatomic, readonly) BOOL isLanguageRightToLeft;
@property (copy, nonatomic, readonly) NSString *currentLanguage;

// TODO: Rename to fleksyInputView to avoid clash with UIViewController's inputView property
/// The common parent view of all the subviews that  make up the keyboard
@property (nonatomic, readonly) UIView *inputView;

// Custom integrator buttons
- (UIImage * _Nullable)imageForCustomButtonWithLabel:(NSString * _Nonnull)label;
- (UIViewContentMode)contentModeForImageInCustomButtonWithLabel:(NSString * _Nonnull)label;

/// To play the haptic feedback whenever the highlighted key due to a long press changes.
- (void)longTapMovedToNewKey;


@end
