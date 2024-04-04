//
//  FleksyTheme.h
//  FleksyKitContainerApp
//
//  Created by Tusi Chowdhury on 2014-07-23.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "FKEnums.h"


#define THEME_CHANGE_DURATION 0.5

typedef enum {
    FleksyThemeTypeDark = 0,
    FleksyThemeTypeLight,
} FleksyThemeType;

typedef enum {
    FleksyGraphicsHardwareEffectNone = 0,
    FleksyGraphicsHardwareEffectHeatmap,
    FleksyGraphicsHardwareEffectMountains
} FleksyGraphicsHardwareEffect;

extern NSArray * ExtensionDefaultJSONFields;
extern NSArray * ContainerDefaultJSONFields;
extern NSArray * AllJSONFields;

/**
 Encapsulates information about a theme.
 */
@interface FleksyTheme : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *jsonString;
@property (readonly, nonatomic) NSArray *backgroundColorArray;
@property (readonly, nonatomic) NSArray *graphicsHardwareEffectColorArray;
@property (nonatomic, readonly) UIImage *backgroundImage;
@property (nonatomic, readonly) NSArray *imageArray;
@property (nonatomic) UIViewContentMode scalingMode;
@property (nonatomic) CGFloat imageAlpha;
@property (readonly, nonatomic) UIColor *homeRowColor __attribute((deprecated("Unused. Returns clear color")));
@property (readonly, nonatomic) UIColor *pressedKeyColor;
@property (readonly, nonatomic) UIColor *spacebarColor;
@property (readonly, nonatomic) UIColor *buttonLetterColor;
@property (readonly, nonatomic) UIColor *buttonBackgroundColor;
@property (readonly, nonatomic) UIColor *pressedButtonColor;
@property (readonly, nonatomic) UIColor *shiftLetterColor;
@property (readonly, nonatomic) UIColor *shiftBackgroundColor;
@property (readonly, nonatomic) UIColor *shiftPressedBackgroundColor;
@property (readonly, nonatomic) UIColor *actionLetterColor;
@property (readonly, nonatomic) UIColor *actionBackgroundColor;
@property (readonly, nonatomic) UIColor *actionPressedBackgroundColor;
@property (readonly, nonatomic) UIColor *spacebarLetterColor;
@property (readonly, nonatomic) UIColor *spacebarBackgroundColor;
@property (readonly, nonatomic) UIColor *spacebarPressedBackgroundColor;
@property (readonly, nonatomic) UIColor *backspaceLetterColor;
@property (readonly, nonatomic) UIColor *backspaceBackgroundColor;
@property (readonly, nonatomic) UIColor *backspacePressedBackgroundColor;
@property (readonly, nonatomic) UIColor *keyPopColor;
@property (readonly, nonatomic) UIColor *plainTileLetterColor;
@property (readonly, nonatomic) UIColor *popTileLetterColor;
@property (readonly, nonatomic) UIColor *keyboardTextColor;
@property (readonly, nonatomic) UIColor *swipeColor;
@property (readonly, nonatomic) UIColor *dimmedTextColor;
@property (readonly, nonatomic) UIColor *outlineColor;
@property (readonly, nonatomic) UIColor *hoverLetters;
@property (readonly, nonatomic) UIColor *hoverBackground;
@property (readonly, nonatomic) UIColor *hoverSelectedLetters;
@property (readonly, nonatomic) UIColor *hoverSelectedBackground;
@property (readonly, nonatomic) UIColor *hoverTouch;
@property (nonatomic, readonly) UIColor *swipeLine;
@property (readonly, nonatomic) UIColor *keyShadow;
@property (readonly, nonatomic) UIColor *buttonShadow;
@property (readonly, nonatomic) UIColor *trackPadCursorColor;

@property (readonly, nonatomic) UIColor *suggestionLetters;
@property (readonly, nonatomic) UIColor *suggestionSelectedLetters;
@property (readonly, nonatomic) UIColor *suggestionBackground;
@property (readonly, nonatomic) UIColor *suggestionSelectedBackground;

@property (nonatomic, readonly) UIColor *appSelectedBackground;
@property (nonatomic, readonly) UIColor *appSelectedLetters;
@property (nonatomic, readonly) UIColor *appSearchBarBackground;
@property (nonatomic, readonly) UIColor *appSearchBarLetters;
@property (nonatomic, readonly) UIColor *appSearchBarCursor;
@property (nonatomic, readonly) UIColor *appFilterSelected;
@property (nonatomic, readonly) UIColor *appFilterLetters;

@property (readonly, nonatomic) NSString *backgroundImageName;
@property (readonly, nonatomic) BOOL hasBackgroundImage;
@property (readonly, nonatomic) BOOL shouldUseImageTransform;
@property (readonly, nonatomic) UIFont *defaultKeyboardFont __attribute((deprecated("Unused. Returns the fontKeyboardNormal")));
@property (nonatomic, strong) UIFont * _Nonnull fontKeyboardNormal;
@property (nonatomic, readonly) FleksyThemeType currentThemeType;
@property (nonatomic) FleksyGraphicsHardwareEffect graphicsHardwareEffect;
@property (nonatomic) BOOL isVibrant;
@property (nonatomic) BOOL isTransparent;
@property (nonatomic) BOOL isUsingGraphicsHardware;
@property (nonatomic, readonly) BOOL rainbowPopEnabled;
@property (nonatomic) BOOL isChameleon;
@property (nonatomic) BOOL isTimeLapse;
@property (nonatomic) BOOL isLogoMono;
@property (nonatomic) BOOL isLookFeelSystem;
@property (nonatomic) BOOL hasCustomTouchView __attribute((deprecated("Unused")));
@property (readonly, nonatomic) BOOL shouldUseOutline;
@property (readonly) BOOL isParallax;
@property (nonatomic, readonly) BOOL isDynamic;
@property (nonatomic, readonly) BOOL changesColorOnSwipe;
@property (nonatomic) CGAffineTransform imageTransform;
@property (nonatomic, readonly) NSString *themeKey;
@property (nonatomic, readonly) BOOL isUserTheme __attribute((deprecated("Unused. Always returns false")));
@property (nonatomic, readonly) BOOL hasCustomSounds;
/**
 Non-square key pops come from the fleksy font. If this is not 0, then
 it should be used instead of a normal key pop view.
 */
@property (nonatomic, readonly) NSArray<NSString *>* keypopCharacters;
@property (nonatomic, readonly) unichar keypopCharacter;
/**
 A theme is generally created by reading a JSON string from the themes.json file
 that ships with Fleksy.
 */
- (instancetype)initWithJSONString:(NSString *)json __attribute((deprecated("FleksyTheme should not be initialized from outside the SDK")));
- (instancetype)initWithThemeDictionary:(NSDictionary *)dict  __attribute((deprecated("FleksyTheme should not be initialized from outside the SDK")));
- (void)resetThemeKey;
- (UIColor *)rainbowPopColor;
- (BOOL)isEqualToTheme:(FleksyTheme *)other;
- (UIFont *)keypadFontForTraitCollection:(UITraitCollection *)traitCollection
                        isLetterKeyboard:(BOOL)isLetters
                            keyboardSize:(KeyboardSize)size
                               landscape:(BOOL)isInLandscape __attribute((deprecated("Returns the same as fontForTraitCollection:isLetterKeyboard:keyboardSize:landscape:")));
- (UIFont *)extensionsFontForTraitCollection:(UITraitCollection *)traitCollection
                            isLetterKeyboard:(BOOL)isLetters
                                keyboardSize:(KeyboardSize)size
                                   landscape:(BOOL)isInLandscape __attribute((deprecated("Returns the same as fontForTraitCollection:isLetterKeyboard:keyboardSize:landscape:")));
- (UIFont * _Nonnull)fontForTraitCollection:(UITraitCollection *)traitCollection
                           isLetterKeyboard:(BOOL)isLetters
                               keyboardSize:(KeyboardSize)size
                                  landscape:(BOOL)isInLandscape;
+ (NSString *)JSONStringForKey:(NSString *)themeKey
                    withFields:(NSArray *)fields;
+ (NSDictionary *) JSONDictionaryForKey:(NSString *)themeKey withFields:(NSArray *)fields;
+ (NSString *)keyForJSONString:(NSString *)themeJSON;
+ (NSDictionary *)themes;
+ (NSURL *)urlForThemeFile;
+ (BOOL)validateJSONDictionary:(NSDictionary *)dictionary;
+ (NSArray<NSString *> *)validThemeGlyphs;

@end
