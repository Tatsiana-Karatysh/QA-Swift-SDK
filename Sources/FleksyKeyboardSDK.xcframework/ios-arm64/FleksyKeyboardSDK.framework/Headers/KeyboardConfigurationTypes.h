//
//  KeyboardConfigurationTypes.h
//  FleksyKeyboardSDK
//
//  Copyright © 2022 Thingthing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AppearanceObject.h"
#import "AppearancePopup.h"
#import "AppearanceLongPress.h"

NS_ASSUME_NONNULL_BEGIN

/**
 - captureOutput_file : store the content of the data capture in a file as JSon format
 - captureOutput_string  : send the data captured via delegate as String as JSon format
 - captureOutput_dictionary : send the data captured via delegate as Dictionary format
 */
typedef NS_ENUM(NSUInteger, enumCaptureOutput){
  captureOutput_file,
  captureOutput_string,
  captureOutput_dictionary
};

/**
 - dataCaptureCoordinate_screenPixel :
 - dataCaptureCoordinate_keyboardPixel :
 - dataCaptureCoordinate_keyboard :
 - dataCaptureCoordinate_internalKeyboard :
 */
typedef NS_ENUM(NSUInteger, enumDataConfigCoordinate) {
  dataConfigCoordinate_screenPixel,
  dataConfigCoordinate_keyboardPixel,
  dataConfigCoordinate_keyboard,
  dataConfigCoordinate_internalKeyboard
};

typedef NS_ENUM(NSUInteger, enumDataConfigFormat) {
    dataConfigFormat_standard,
    dataConfigFormat_groupByTap
};

//
// Specific data to capture if we want to customise what we capture
//
@interface FLDataConfiguration : NSObject<NSCopying>

@property (nonatomic, nullable, readonly) NSMutableDictionary* configuration;
@property (assign, nonatomic, readonly) BOOL accelerometer;

- (instancetype) init;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

- (instancetype) initWithText:(BOOL)dataText
                        swipe:(BOOL)dataSwipe
                        emoji:(BOOL)dataEmoji
                       layout:(BOOL)dataLayout
                    textField:(BOOL)dataTextField
                     language:(BOOL)dataLanguage
                         type:(BOOL)dataType
                         area:(BOOL)dataArea
                         code:(BOOL)dataCode
                     position:(BOOL)dataPosition
                        press:(BOOL)dataPress
                     keyPress:(BOOL)dataKeyPress
                    keyCenter:(BOOL)dataKeyCenter
                    keyBounds:(BOOL)dataKeyBounds
             configCoordinate:(enum enumDataConfigCoordinate)dataConfigCoordinate
                         word:(BOOL)dataWord
                       delete:(BOOL)dataDelete
                     keyPlane:(BOOL)dataKeyPlane
                      keyText:(BOOL)dataKeyText
                  positionEnd:(BOOL)dataPositionEnd
                  keyPressEnd:(BOOL)dataKeyPressEnd
             predictionsTouch:(BOOL)dataPredictionsTouch
                   prediction:(BOOL)dataPrediction
                 configFormat:(enum enumDataConfigFormat)dataConfigFormat
                accelerometer:(BOOL)dataAccelerometer
               autocorrection:(BOOL)dataAutocorrection
        distanceFromLastTouch:(BOOL)distanceFromLastTouch
           keyPositionLimited:(BOOL)dataKeyPositionLimited
        autocorrectionLimited:(BOOL)dataAutocorrectionLimited
                  wordLimited:(BOOL)dataWordLimited
            predictionLimited:(BOOL)dataPredictionLimited
                 swipeLimited:(BOOL)dataSwipeLimited
                deleteLimited:(BOOL)dataDeleteLimited
        interKeyTimeHistogram:(BOOL)interKeyTimeHistogram
interKeyTimeHistogramInterval:(NSInteger)interKeyTimeHistogramInterval
   interKeyTimeHistogramCount:(NSInteger)interKeyTimeHistogramCount NS_SWIFT_NAME(init(_text:_swipe:_emoji:_layout:_textField:_language:_type:_area:_code:_position:_press:_keyPress:_keyCenter:_keyBounds:_configCoordinate:_word:_delete:_keyPlane:_keyText:_positionEnd:_keyPressEnd:_predictionsTouch:_prediction:_configFormat:_accelerometer:_autocorrection:_distanceFromLastTouch:_keyPositionLimited:_autocorrectionLimited:_wordLimited:_predictionLimited:_swipeLimited:_deleteLimited:_interKeyTimeHistogram:_interKeyTimeHistogramInterval:_interKeyTimeHistogramCount:));

- (instancetype) initWithText:(BOOL)dataText
                        swipe:(BOOL)dataSwipe
                        emoji:(BOOL)dataEmoji
                       layout:(BOOL)dataLayout
                    textField:(BOOL)dataTextField
                     language:(BOOL)dataLanguage
                         type:(BOOL)dataType
                         area:(BOOL)dataArea
                         code:(BOOL)dataCode
                     position:(BOOL)dataPosition
                        press:(BOOL)dataPress
                     keyPress:(BOOL)dataKeyPress
                    keyCenter:(BOOL)dataKeyCenter
                    keyBounds:(BOOL)dataKeyBounds
             configCoordinate:(enum enumDataConfigCoordinate)dataConfigCoordinate
                         word:(BOOL)dataWord
                       delete:(BOOL)dataDelete
                     keyPlane:(BOOL)dataKeyPlane
                      keyText:(BOOL)dataKeyText
                  positionEnd:(BOOL)dataPositionEnd
                  keyPressEnd:(BOOL)dataKeyPressEnd
             predictionsTouch:(BOOL)dataPredictionsTouch
                   prediction:(BOOL)dataPrediction
                 configFormat:(enum enumDataConfigFormat)dataConfigFormat
                accelerometer:(BOOL)dataAccelerometer
               autocorrection:(BOOL)dataAutocorrection
        distanceFromLastTouch:(BOOL)distanceFromLastTouch
           keyPositionLimited:(BOOL)dataKeyPositionLimited
        autocorrectionLimited:(BOOL)dataAutocorrectionLimited
                  wordLimited:(BOOL)dataWordLimited
            predictionLimited:(BOOL)dataPredictionLimited
                 swipeLimited:(BOOL)dataSwipeLimited
                deleteLimited:(BOOL)dataDeleteLimited
                stressMonitor:(BOOL)dataStressMonitor
        interKeyTimeHistogram:(BOOL)interKeyTimeHistogram
interKeyTimeHistogramInterval:(NSInteger)interKeyTimeHistogramInterval
   interKeyTimeHistogramCount:(NSInteger)interKeyTimeHistogramCount NS_SWIFT_NAME(init(_text:_swipe:_emoji:_layout:_textField:_language:_type:_area:_code:_position:_press:_keyPress:_keyCenter:_keyBounds:_configCoordinate:_word:_delete:_keyPlane:_keyText:_positionEnd:_keyPressEnd:_predictionsTouch:_prediction:_configFormat:_accelerometer:_autocorrection:_distanceFromLastTouch:_keyPositionLimited:_autocorrectionLimited:_wordLimited:_predictionLimited:_swipeLimited:_deleteLimited:_stressMonitor:_interKeyTimeHistogram:_interKeyTimeHistogramInterval:_interKeyTimeHistogramCount:));


- (nullable NSString*) convertDictionaryToJSON;
- (void)setScreenDimensionsWithScreen:(UIScreen *)screen;
- (void) addPropertyToConfiguration:(NSString*) key objectNumber:(NSNumber*) object;
- (void) addPropertyToConfiguration:(NSString*) key objectString:(NSString*) object;

@end

//
//  CaptureConfiguration with all the capture parameters
//
@interface CaptureConfiguration : NSObject<NSCopying>

/// Creates a new instance of `CaptureConfiguration`.
/// @param enabled A boolean indicating whether data capture should be enabled.
/// @param output The type of output for the captured data.
- (instancetype) initWith:(BOOL) enabled output:(enumCaptureOutput) output;

/// Creates a new instance of @c CaptureConfiguration .
/// @param enabled A boolean indicating whether data capture should be enabled.
/// @param output The type of output for the captured data.
/// @param dataConfig The specific configuration for the captured data.
- (instancetype) initWith:(BOOL) enabled output:(enumCaptureOutput) output dataConfig:(FLDataConfiguration * _Nonnull) dataConfig;

/// Creates a new instance of @c CaptureConfiguration .
/// @param enabled A boolean indicating whether data capture should be enabled.
/// @param output The type of output for the captured data.
/// @param dataConfig The specific configuration for the captured data.
/// @param logEvents A boolean indicating whether data capture events should be logged.
- (instancetype) initWith:(BOOL) enabled output:(enumCaptureOutput) output dataConfig:(FLDataConfiguration*) dataConfig logEvents:(BOOL)logEvents;

/// A boolean indicating whether data capture should be enabled.
@property (nonatomic) BOOL enabled;

/// The type of output for the captured data.
@property (nonatomic) enumCaptureOutput output;

/// The specific configuration for the captured data.
@property (nonatomic) FLDataConfiguration* dataConfig;

/// A boolean indicating whether data capture events should be logged.
@property (assign, nonatomic) BOOL logEvents;

// Enable to receive analytics report automatically generated
// by the KeyboardSDK
// It contains autocorrection errors, ...
@property (nonatomic) BOOL enabledReportAnalytics;

@end

//
// SpaceBar Configuration to configure logo / languages in the spacebar
//

/// This enum defines the behavior of the spacebar in terms of style and labeling.
typedef NS_ENUM(NSUInteger, enumSpacebarStyle){
    /// The spacebar shows the user language when there's more than one language configured. Otherwise, it will show the ``StyleConfiguration/spacebarLogoImage`` if it is not `nil`.
    spacebarStyle_Automatic     = 0,
    
    /// The spacebar always shows the ``StyleConfiguration/spacebarLogoImage``. If the logo is `nil`, then it shows nothing.
    spacebarStyle_LogoOnly      = 1,
    
    /// The spacebar shows the current user language, only if there's more than one language configured (regardless of whether or not there logo image has been set).
    spacebarStyle_LanguageOnly  = 2
};

DEPRECATED_MSG_ATTRIBUTE("AppearanceConfiguration API is deprecated and ignored") @interface AppearanceConfiguration : NSObject<NSCopying>

- (instancetype) initWithObjPopup:(nullable AppearancePopup*) objPoup
                         objTouch:(nullable AppearanceObject*) objTouch
                     objLongpress:(nullable AppearanceLongPress*)  objLongpress;
@property (nonatomic) AppearancePopup* appearancePopup;
@property (nonatomic) AppearanceObject* appearanceTouch;
@property (nonatomic) AppearanceLongPress* appearanceLongpress;
@property (nonatomic) UIEdgeInsets insetsKeyboard;
@end

//
// Emoji Configuration to configure emoji configuration
//
typedef NS_ENUM(NSUInteger, enumEmojiSkinTone){
  emojiSkinTone_Neutral       = 0,
  emojiSkinTone_Light         = 1,
  emojiSkinTone_Medium_Light  = 2,
  emojiSkinTone_Medium        = 3,
  emojiSkinTone_Medium_Dark   = 4,
  emojiSkinTone_Dark          = 5
};

//
// Debug Configuration to set up properties for debugging the SDK
//
@interface DebugConfiguration : NSObject<NSCopying>

// Enable every possible flag to debug
- (instancetype) initDebug;

@property (nonatomic) BOOL registerLayoutChange;

@end

//
// Special Keys Configuration to set up Magic Button
//
// By default, we have keep the basic configuration for the SDK
// with different elements from the array
DEPRECATED_MSG_ATTRIBUTE("The SpecialKeysConfiguration API is deprecated and will be removed in a future release. You can use TypingConfiguration's magicButtonAction and magicButtonLongPressActions parameters to fully customize the magic button")
@interface SpecialKeysConfiguration: NSObject<NSCopying>

// Long press on special key left to space bar appears
// different options, that we call "magic button actions"
@property (nonatomic) NSArray* arrayMagicButton __attribute((deprecated("The SpecialKeysConfiguration API is deprecated and will be removed in a future release. You can use TypingConfiguration's magicButtonAction and magicButtonLongPressActions parameters to fully customize the magic button")));

@end

//
// Panel Configuration: topbar height, customTopBar View, ..
//
DEPRECATED_MSG_ATTRIBUTE("PanelConfiguration API is deprecated and will be removed in a future release. You can use FleksyApps via AppsConfiguration to have a fully customizable top bar")
@interface PanelConfiguration: NSObject<NSCopying>

/// This flag enables customTopbar, by default, not enabled
@property (nonatomic) BOOL enableCustomTopBar;

/// If @c enableCustomTopBar is @c YES, we use this value for the height, in points, of the topbar, with a minimum height of 44 pts.
@property (nonatomic) CGFloat heightTopBar;

@end

/// -- Keyboard Dynamic Configuration --
///  -- Configuration that is able to be reloaded at any time
@interface KeyboardDynamicConfiguration : NSObject<NSCopying>

// If we have enabled custom top bar height, we can change the height of it dynamically
// In case that we do not have this enabled, we cannot change the height if we do not reload the keyboard
@property (nonatomic) float heightCustomTopBar;

@end

NS_ASSUME_NONNULL_END
