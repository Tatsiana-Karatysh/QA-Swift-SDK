//  FleksyInternalDefines.h
//  FleksyKeyboardSDK
//
//  Copyright © 2022 Thingthing. All rights reserved.
//

typedef NS_ENUM(NSInteger, FleksyXtrasType) {
  FleksyXtraHighlights,
  FleksyXtraEmptyView,
};

/// The key to be used by integrators in their targets' info.plist to specify the identifier of the shared app group.
extern NSString * const FLEKSY_SDK_SHARED_APP_GROUP_IDENTIFIER_PLIST_KEY;

/// `UserDefaults` key whose value contains an `NSNumber` with the last section seen in the emoji keyboard.
/// The SDK writes to this setting whenever the user changes emoji section so that the next time the emoji keyboard opens the last-seen section is presented.
extern NSString * const FLEKSY_SETTINGS_EMOJI_LAST_SECTION;

extern NSString * const FLEKSY_SETTINGS_LAST_CONTAINER_SETTINGS_UPDATE_URL_EXTENSION;

/// Internal `UserDefaults` flag to know if the SDK has ever had its first initialization complete.
///
/// When there is no value for this key, the SDK understand that this is the first initialization of the SDK and then saves the default values for the required keys in `UserDefaults`.
extern NSString * const FLEKSY_SETTINGS_SDK_INITIALIZED;

extern NSString * const FLEKSY_SETTINGS_UNDERLINE_SPELL_CHECK;

/// Internal `UserDefaults` flag to determine if the keyboard should show the long-pressed letter when showing its accents. Defaults to `false`.
///
/// E.g. when long-pressing the letter "a":
/// * If this setting is `true`, then the popup shows the accented versions of the letter "a" as well as the letter "a" itself.
/// * If this setting is `false`, then the popup only shows the accented versions of the letter "a", not including the letter "a" itself.
extern NSString * const FLEKSY_SETTINGS_KEYPRESS_AS_ACCENT;

/// Internal `UserDefaults` flag to store the ``FleksyManagedSettings/punctuationSymbols`` setting.
extern NSString * const FLEKSY_SETTINGS_PUNCTUATION_SYMBOLS;

/// Internal `UserDefaults` flag to store the ``FleksyManagedSettings/numberRow`` setting.
extern NSString * const FLEKSY_SETTINGS_NUMBER_ROW;

/// Internal `UserDefaults` flag to store the ``FleksyManagedSettings/lightKeyboardTheme`` setting.
extern NSString * const FLEKSY_SETTINGS_LIGHT_KEYBOARD_THEME;

/// Internal `UserDefaults` flag to store the ``FleksyManagedSettings/darkKeyboardTheme`` setting.
extern NSString * const FLEKSY_SETTINGS_DARK_KEYBOARD_THEME;

/// Internal `UserDefaults` flag to store the ``FeedbackConfiguration/soundMode-swift.property`` setting.
extern NSString * const FLEKSY_SETTINGS_SOUND_MODE;

/// Internal `UserDefaults` flag to store the ``FeedbackConfiguration/haptics`` setting.
extern NSString * const FLEKSY_SETTINGS_HAPTICS;

/// Internal `UserDefaults` flag to store the ``AppsConfiguration/showAppsInCarousel`` setting.
extern NSString * const FLEKSY_SETTINGS_SHOW_APPS_IN_CAROUSSEL;
