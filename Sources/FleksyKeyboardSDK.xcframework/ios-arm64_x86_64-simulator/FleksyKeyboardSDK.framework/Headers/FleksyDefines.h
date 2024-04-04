//
//  FleksyDefines.h
//  FleksyFramework
//
//  Created by Tusi Chowdhury on 2014-09-30.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#ifndef FleksyFramework_FleksyDefines_h

#define FleksyFramework_FleksyDefines_h

#include <Foundation/Foundation.h>

static inline void NS_FORMAT_FUNCTION(1, 2) _FSLogNull(NSString *format, ...) { (void)format; }

//#define FLEKSY_BUILDING_FOR_APPSTORE

//GLOBALS
#if defined(DEBUG) && DEBUG
  #define FSLOG(format, ...)  NSLog(@"%@(%d): " format, @(__PRETTY_FUNCTION__), __LINE__, ##__VA_ARGS__)
#else
  #define FSLOG(format, ...) _FSLogNull(format, ##__VA_ARGS__)
#endif

#define LOG_TOUCHES 1
#if LOG_TOUCHES
#define FSTLOG(format, ...) FSLOG(@"Touch Log: %@(%d): " format, @(__PRETTY_FUNCTION__), __LINE__, ##__VA_ARGS__)
#else
#define FSTLOG(format, ...) _FSLogNull(format, ##__VA_ARGS__)
#endif

#define LOG_TEXT_INPUT_INTERACTION 1
#if LOG_TOUCHES
#define FSTILOG(format, ...) FSLOG(@"Touch Log: %@(%d): " format, @(__PRETTY_FUNCTION__), __LINE__, ##__VA_ARGS__)
#else
#define FSTILOG(format, ...) _FSLogNull(format, ##__VA_ARGS__)
#endif

#define FLKeyboardSize_HUGE_Str @"FLKeyboardSize_HUGE"
#define FLKeyboardSize_LARGE_Str @"FLKeyboardSize_LARGE"
#define FLKeyboardSize_ORIGINAL_Str @"FLKeyboardSize_ORIGINAL"
#define FLKeyboardSize_SMALL_Str @"FLKeyboardSize_SMALL"
#define FLKeyboardSize_TINY_Str @"FLKeyboardSize_TINY"

#define FLEmojiSkinTone_Neutral_Str @"FLEmojiSkinTone_Neutral"
#define FLEmojiSkinTone_Light_Str @"FLEmojiSkinTone_Light"
#define FLEmojiSkinTone_MediumLight_Str @"FLEmojiSkinTone_MediumLight"
#define FLEmojiSkinTone_Medium_Str @"FLEmojiSkinTone_Medium_Str"
#define FLEmojiSkinTone_MediumDark_Str @"FLEmojiSkinTone_MediumDark"
#define FLEmojiSkinTone_Dark_Str @"FLEmojiSkinTone_Dark"

extern NSString *const kDefaultThemeString __attribute((deprecated("For a default theme that adapts to both light and dark appearances, use the initializer of StyleConfiguration that has no parameters")));

/// A notification with this name is sent whenever the keyboard ID changes. The object the notification is a `NSNumber` containing the new keyboard ID (as defined by the ``KeyboardID`` enum).
static NSString * const FLEKSY_KEYBOARD_ID_DID_CHANGE = @"FleksyKeyboardIDDidChange";

/// The key in `UserDefaults` for the autocorrection setting. The value is a `NSNumber` treated as a `Bool`.
///
/// The SDK writes to this setting whenever the user changes the auto-correction setting from the keyboard (using the auto-correct toggle magic button). Also, if you include the `autoCorrect` parameter in the ``TypingConfiguration`` initialization, then the SDK writes that value in `UserDefaults` for this key.
extern NSString * const FLEKSY_SETTINGS_USER_AUTO_CORRECTION __attribute((deprecated("Use FleksyManagedSettings.autocorrect or the autoCorrect parameter in TypingConfiguration")));

extern NSString * const FLEKSY_SETTINGS_USER_AUTO_CAPITALIZATION __attribute((deprecated("Use FleksyManagedSettings.autoCapitalization or the autoCapitalization parameter in TypingConfiguration")));

extern NSString * const FLEKSY_SETTINGS_THEME __attribute((deprecated("Use StyleConfiguration APIs. The value in UserDefaults for this key is ignored")));
extern NSString * const FLEKSY_SETTINGS_SPEAK;
extern NSString * const FLEKSY_SETTINGS_KEYBOARD_CLICKS;
extern NSString * const FLEKSY_SETTINGS_TYPING_SOUNDS;

extern NSString * const FLEKSY_SETTINGS_SPACEBAR_ROW __attribute((deprecated("Use FleksyManagedSettings.isMinimal or the isMinimal parameter in TypingConfiguration")));

/// `UserDefaults` key whose value contains the current locale of the keyboard.
///
/// The SDK updates the value for this key in `UserDefaults` whenever the keyboard language changes, saving in `UserDefaults` the locale of the latest keyboard language. The keyboard language can change for multiple reasons:
/// * When the user swipes the spacebar horizontally to switch languages
/// * When calling ``LanguagesHelper``'s ``LanguagesHelper/addLanguage(_:)`` method
/// * When calling ``LanguagesHelper``'s ``LanguagesHelper/deleteLanguage(_:)`` to delete the current language (and the keyboard changes automatically to the next language).
extern NSString * const FLEKSY_SETTINGS_LANGUAGE_PACK_KEY;

/// `UserDefaults` key whose value contains an array of dictionaries. Each dictionary has two keys;
/// * Key `FLEKSY_SETTINGS_LANGUAGE_LETTER_LAYOUTS_CODE_KEY`. Its value is a language locale `String` (e.g. `"en-US"`).
/// * Key `FLEKSY_SETTINGS_LANGUAGE_LETTER_LAYOUTS_CURRENT_LAYOUT_KEY`. Its value is a layout `String` containing the preferred layout to use for the associated locale (e.g. `"QWERTY"`).
///
/// Use ``LanguagesHelper``'s ``LanguagesHelper/getCurrentLayoutForLanguage(_:)`` method to easily obtain the setting in `UserDefaults` for the default layout for a given language.
extern NSString * const FLEKSY_SETTINGS_LANGUAGE_LETTER_LAYOUTS __attribute((deprecated("Use FleksyManagedSettings.userLanguages")));

/// Key for the dictionaries stored in `UserDefaults` for the `FLEKSY_SETTINGS_LANGUAGE_LETTER_LAYOUTS` key. Its value is a language locale `String` (e.g. `"en-US"`).
extern NSString * const FLEKSY_SETTINGS_LANGUAGE_LETTER_LAYOUTS_CODE_KEY;

/// Key for the dictionaries stored in `UserDefaults` for the `FLEKSY_SETTINGS_LANGUAGE_LETTER_LAYOUTS` key. Its value is a layout `String` containing the preferred layout to use for the associated locale (e.g. `"QWERTY"`).
extern NSString * const FLEKSY_SETTINGS_LANGUAGE_LETTER_LAYOUTS_CURRENT_LAYOUT_KEY;

/// `UserDefaults` key whose value contains an array of locale `String`s, meaning the order of installed languages for fast-switching in the keyboard.
///
/// The SDK writes to this setting when adding or deleting a language using ``LanguagesHelper``'s ``LanguagesHelper/addLanguage(_:)`` or ``LanguagesHelper/deleteLanguage(_:)``. Also, if you include the `language` parameter in the ``KeyboardConfiguration`` initialization, then the SDK writes that value in `UserDefaults` for this key.
extern NSString * const FLEKSY_SETTINGS_LANGUAGE_INSTALLED_ORDER __attribute((deprecated("Use FleksyManagedSettings.userLanguages")));

/// `UserDefaults` key whose value is a `String` containing the recently-selected emojis.
///
/// The SDK writes to this setting whenever the user selects an emoji from the emoji keyboard.
/// In adition, when you include the `recent` parameter in the ``EmojiConfiguration`` initialization, the SDK overrides this setting with the emojis in that parameter.
extern NSString * const FLEKSY_SETTINGS_RECENT_USED_EMOJIS __attribute((deprecated("Use FleksyManagedSettings.recentEmojis or the recentEmojis parameter in EmojiConfiguration")));

/// Default skin tone for all compatible emojis
/// - FLEmojiSkinTone_Neutral_Str
/// - FLEmojiSkinTone_Light_Str
/// - FLEmojiSkinTone_MediumLight_Str
/// - FLEmojiSkinTone_Medium_Str
/// - FLEmojiSkinTone_MediumDark_Str
/// - FLEmojiSkinTone_Dark_Str
extern NSString * const FLEKSY_SETTINGS_DEFAULT_EMOJI_SKIN_TONE __attribute((deprecated("Use FleksyManagedSettings.defaultEmojiSkinTone or the defaultSkinTone parameter in EmojiConfiguration")));

/// Individual skin tone for emojis as used by the user.
///
/// The value in `UserDefaults` for this key contains a dictionary where each key is an emoji text and the value is the skin tone variation of that emoji last selected by the user. If an emoji compatible with different skin tone variations is not present in the dictionaty, then it means that the user has not selected yet a skin tone variation for that emoji different to the default skin tone specified by the `EmojiConfiguaration` object.
///
/// The SDK modifies this setting whenever the user long-presses a compatible emoji and selects the skin tone variation for that emoji. You should not read or write this setting unless you want to tweak the user's preferences for emojis compatible with skin tone variations. But note that the SDK will keep modifying this setting based on user's selections.
extern NSString * const FLEKSY_SETTINGS_EMOJI_RACE_PREFERENCES;

extern NSString * const FLEKSY_SETTINGS_USE_ALL_ACCENTS __attribute((deprecated("Use FleksyManagedSettings.useAllAccents or the useAllAccents parameter in TypingConfiguration")));

extern NSString * const FLEKSY_SETTINGS_DOUBLE_TAP_PERIODS __attribute((deprecated("Use FleksyManagedSettings.doubleSpaceTapAddsPunctuation or the doubleSpaceTapAddsPunctuation parameter in TypingConfiguration")));
extern NSString * const FLEKSY_SETTINGS_KEYPAD_FONT __attribute((deprecated("Use FleksyManagedSettings.keyboardFont or the keyboardFont parameter in StyleConfiguration")));
extern NSString * const FLEKSY_SETTINGS_LONGPRESS_PUNCTUATION __attribute((deprecated("Use FleksyManagedSettings.longPressShowsPunctuation or the longPressShowsPunctuation parameter in TypingConfiguration")));

/// This setting requires `FLEKSY_SETTINGS_USER_AUTO_CORRECTION` to be active
extern NSString * const FLEKSY_SETTINGS_AUTOCORRECT_WITH_PUNCTUATION __attribute((deprecated("Use FleksyManagedSettings.autocorrectAfterPunctuation or the autocorrectAfterPunctuation parameter in TypingConfiguration")));
extern NSString * const FLEKSY_SETTINGS_SHOW_WORD_PREDICTIONS __attribute((deprecated("Use FleksyManagedSettings.wordPredictions or the wordPredictions parameter in PredictionsConfiguration")));
extern NSString * const FLEKSY_SETTINGS_DISABLE_SMART_SPACING __attribute((deprecated("Use FleksyManagedSettings.smartPunctuation or smartPunctuation parameter in TypingConfiguration")));
extern NSString * const FLEKSY_SETTINGS_AUTOLEARN_FROM_USER __attribute((deprecated("Use FleksyManagedSettings.autoLearn or the autoLearn parameter in TypingConfiguration")));
extern NSString * const FLEKSY_SETTINGS_SWIPE_LENGTH __attribute((deprecated("Use FleksyManagedSettings.swipeTriggerLength or the swipeTriggerLength parameter in TypingConfiguration")));
extern NSString * const FLEKSY_SETTINGS_DELETE_CORRECTION __attribute((deprecated("Use FleksyManagedSettings.backspaceToUndoAutoCorrection or the backspaceToUndoAutoCorrection parameter in TypingConfiguration")));

extern NSString * const FLEKSY_SETTINGS_SWIPETYPING __attribute((deprecated("Use FleksyManagedSettings.swipeTyping or the swipeTyping parameter in TypingConfiguration")));

extern NSString * const FLEKSY_SETTINGS_LEFT_SWIPE_DELETE __attribute((deprecated("Use FleksyManagedSettings.swipeLeftToDelete or the swipeLeftToDelete parameter in TypingConfiguration")));
extern NSString * const FLEKSY_SETTINGS_REPORT_ANALYTICS;
extern NSString * const FLEKSY_SETTINGS_EMOJI_SUGGESTION __attribute((deprecated("Use FleksyManagedSettings.emojiPredictions or the emojiPredictions parameter in PredictionsConfiguration")));
extern NSString * const FLEKSY_SETTINGS_EMOJI_PREDICTION __attribute((deprecated("Use FleksyManagedSettings.emojiPredictions or the emojiPredictions parameter in PredictionsConfiguration")));

extern NSString * const FLEKSY_SETTINGS_LONG_PRESS_SPACEBAR_MOVE_CURSOR __attribute((deprecated("Use FleksyManagedSettings.spacebarMovesCursor or the spacebarMovesCursor parameter in TypingConfiguration")));

extern NSString * const FLEKSY_SETTINGS_KEYBOARD_SIZE __attribute((deprecated("Use FleksyManagedSettings.keyboardSize or the keyboardSize parameter in StyleConfiguration")));

extern NSString * const FLEKSY_SETTINGS_DidChangeNotification;

extern NSString * const FLEKSY_SETTINGS_DISPLAY_LOWERCASE_LETTERS __attribute((deprecated("Use FleksyManagedSettings.caseSensitive or the caseSensitive parameter in TypingConfiguration")));

/// `UserDefaults` key whose value is a `String` containing the version of the Fleksy Engine dependency.
///
/// Note that for this value only updates after the SDK has been initialized (i.e. after the keyboard opens)
extern NSString * const FLEKSY_ENGINE_VERSION;

/// `UserDefaults` key whose value is a `NSNumber` containing the raw value of a ``FleksyControlType`` that should be used as the magic button, that is the button to the left of the spacebar.
///
/// This setting is ignored when passing the `magicButtonAction` parameter in the ``TypingConfiguration``.
extern NSString * const FLEKSY_SETTINGS_CONFIGURABLE_BUTTON __attribute((deprecated("Use FleksyManagedSettings.magicButtonAction or the magicButtonAction parameter in TypingConfiguration")));

/// `UserDefaults` key whose value is an array of `NSNumber` containing the raw values of the ``FleksyControlType``s that should be used when the user long-presses the magic button (that is the button to the left of the spacebar). After the long-press, a popup shows with the magic buttons defined by this setting (just as the accents show when pressing a letter).
///
/// This setting is ignored when passing the `magicButtonLongPressActions` parameter in the ``TypingConfiguration``.
extern NSString * const FLEKSY_SETTINGS_MAGIC_BUTTON_ORDER __attribute((deprecated("Use FleksyManagedSettings.magicButtonLongPressActions or the magicButtonLongPressActions parameter in TypingConfiguration")));

/// The default delay for Keitai rotation in Flick layout for Japanese. 1 second.
static NSTimeInterval const FLEKSY_DEFAULT_KEITAI_DELAY = 1.0;

/// Contains a @c BOOL indicating whether or not Keitai typing is enabled for the Japanese Flick keyboard The SDK defaults to enabling the Keitai typing if there's no value set for this key.
extern NSString * const FLEKSY_SETTINGS_KEITAI_ENABLED __attribute((deprecated("Use FleksyManagedSettings.keitaiEnabled or the keitaiEnabled parameter in TypingConfiguration")));

/// Contains a @c NSNumber  indicating the delay time, in seconds, for the Keitai rotations. Only effective when Keitai typing is enabled (see @c FLEKSY_SETTINGS_KEITAI_ENABLED ).
///
/// The SDK defaults the seconds of Keitai rotation delay to @c FLEKSY_DEFAULT_KEITAI_DELAY if there's no value set for this key.
extern NSString * const FLEKSY_SETTINGS_KEITAI_DELAY __attribute((deprecated("Use FleksyManagedSettings.keitaiDelay or the keitaiDelay parameter in TypingConfiguration")));

/// The locale of the keyboard language bundled with the SDK: `"en-US"`.
extern NSString * const FLEKSY_SDK_BUNDLED_LANGUAGE_LOCALE;

// Notifications to subscribe
extern NSString* const NOTIFICATION_KEY_PRESSED;
extern NSString* const NOTIFICATION_KEY_RELEASED;
extern NSString* const NOTIFICATION_KEY_SWIPE_RELEASED;
extern NSString* const NOTIFICATION_KEY_LONGPRESS_RELEASED;
extern NSString* const NOTIFICATION_KEY_NEW_NWP;


typedef enum {
  FleksyControlTypeShiftKey,
  FleksyControlTypeNumbersKey,
  FleksyControlTypeLettersKey,
  FleksyControlTypeSymbolsKey,
  FleksyControlTypeSpaceKey,
  FleksyControlTypeNumPadSpaceKey,
  FleksyControlTypeNumPadZeroKey,
  FleksyControlTypeBackspaceKey,
  FleksyControlTypeEnterKey,
  FleksyControlTypeGlobeKey,
  FleksyControlTypePeriodKey,
  FleksyControlTypeAtSignKey,
  FleksyControlTypeEmojiKey,
  FleksyControlTypeCommaKey,
  FleksyControlTypeHashKey,
  FleksyControlTypeHideKeyboardKey,
  FleksyControlTypeAutoCorrectOffKey,
  FleksyControlTypeTotalKeys,         // Total hardcoded keys. After these ones, we could add custom ones.
} FleksyControlType;

typedef NS_ENUM(NSUInteger, FleksyTouchType) {
  FleksyTouchTypeUnknown = 0,
  FleksyTouchTypeTap = 1,
  FleksyTouchTypeSwipeLeft = 2,
  FleksyTouchTypeSwipeRight = 3,
  FleksyTouchTypeSwipeUp = 4,
  FleksyTouchTypeSwipeDown = 5,
  FleksyTouchTypeTwoFingerSwipeUp = 6,
  FleksyTouchTypeTwoFingerSwipeDown = 7,
  FleksyTouchTypeLongPress = 8,
  FleksyTouchTypeForceTouch = 9,
};

typedef enum {
  FleksyPermissionNone,
  FleksyPermissionGranted,
  FleksyPermissionSoftRejected,
  FleksyPermissionRejected
} FleksyPermission;

typedef NS_ENUM(NSUInteger, FleksyTextChangeEventType) {
  FleksyTextChangeEventTypeNoChange,
  FleksyTextChangeEventTypeNewField,
  FleksyTextChangeEventTypeCursorPositionOrTextChange,
};

#endif
