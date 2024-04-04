//  FKEnums.h
//  FleksyKeyboardSDK
//
//  Copyright © 2022 Thingthing. All rights reserved.
//

// Word Predictions definitions
typedef enum {
  WordPrediction_EnteredText = 0,               // Entered Text directly from the user
  WordPrediction_Suggestion = 1,                // Suggestion word
  WordPrediction_AutoCorrection = 2,            // Word that the engine will autocorrect
  WordPrediction_EnteredText_AutoCorrection = 3,// Word entered by the user is the same as the one that Engine will correct
  WordPrediction_Emoji = 4,                     // Emoji suggestion
  WordPrediction_Unknown = 5                    // Don't know or undefined
}WordPredictionType;

typedef int ButtonType;
static const int ButtonType_Other          = 0;
static const int ButtonType_Letter         = 1;
static const int ButtonType_Shift_Off      = 2;
static const int ButtonType_Enter          = 3;
static const int ButtonType_Spacer         = 4;
static const int ButtonType_Space          = 5;
static const int ButtonType_Backspace      = 6;
static const int ButtonType_Emoji          = 7;
static const int ButtonType_Symbols        = 8;
static const int ButtonType_Henkan_Left    = 9;
static const int ButtonType_Henkan_Right   = 10;
static const int ButtonType_Language       = 11;
static const int ButtonType_Letters_Switch = 12; //Button for lettersLayout
static const int ButtonType_Magic          = 13;
static const int ButtonType_Punctuation    = 14;
static const int ButtonType_Numbers        = 15;
static const int ButtonType_Next           = 16;
static const int ButtonType_Previous       = 17;
static const int ButtonType_Mic_On         = 19;
static const int ButtonType_Mic_Off        = 20;
static const int ButtonType_Numpad_Symbols = 21;
static const int ButtonType_Shift_On       = 22;
static const int ButtonType_Caps_On        = 23;
static const int ButtonType_Language_Left  = 24;
static const int ButtonType_Language_Right = 25;
static const int ButtonType_Letter_Button  = 26;
static const int ButtonType_CandidateView2D= 27;
static const int ButtonType_FlickPunc      = 28; // Appears only on ja-JP Flick layout.
static const int ButtonType_DropDown       = 29;
static const int ButtonType_ReturnToEmoji  = 30;
static const int ButtonType_EmoLangSwitch  = 31;
static const int ButtonType_Phonepad_Symbols = 32;
static const int ButtonType_LongPress_Type = 33;
static const int ButtonType_CustomLabel = 34;

typedef enum {
  KeyboardSize_Huge,
  KeyboardSize_LARGE,
  KeyboardSize_ORIGINAL,
  KeyboardSize_SMALL,
  KeyboardSize_TINY,
  KeyboardSize_NOT_SET
}KeyboardSize;

typedef enum { // Copy of Engine's FLCorrectionMode
  CorrectionMode_URL, // In this mode, when . is entered previous TB is not corrected
  CorrectionMode_ALWAYS,
  CorrectionMode_OFF
} CorrectionMode;


typedef enum { // Copy of Engine's FLMessageType
  MessageType_DEBUG,
  MessageType_NO_NEXT_SUGGESTION,
  MessageType_NO_PREVIOUS_SUGGESTION,
  MessageType_EVENT,
  MessageType_ERROR,
  MessageType_ERROR1, // FLTypingController::correctToNextSuggestion
  MessageType_ERROR2, // unused
  MessageType_ERROR3, // FLTypingController::updateCandidatesView
  MessageType_ERROR4, // unused
  MessageType_BACKSPACE,
  MessageType_SPACEBAR_STATE_PUNCTUATION,
  MessageType_SPACEBAR_STATE_CLEAR,
  MessageType_SD_WHILE_TYPING_SINCE_LAST_AU,
  MessageType_NEXT_SUGGESTION // Suggest NEXT to show up suggestions while browsing
} MessageType;


typedef enum { // Copy of Engine's FLMessageType
  KeyboardID_QWERTY_LOWER = 0,    // 0
  KeyboardID_QWERTY_UPPER,        // 1
  KeyboardID_NUMBERS,             // 2
  KeyboardID_SYMBOLS,             // 3
  KeyboardID_QWERTY_AC_OFF_LOWER, // 4
  KeyboardID_EMOJIS,              // 5
  KeyboardID_NUMBER_PAD,          // 6
  KeyboardID_NUMBER_PAD_SYMBOLS,  // 7
  KeyboardID_SHIFT_1,             // 8
  KeyboardID_SHIFT_2,             // 9
  KeyboardID_SHIFT_3,             // 10
  KeyboardID_NUMBERS_IOS,         // 11
  KeyboardID_SYMBOLS_IOS,         // 12
  KeyboardID_TEMP,                // 13
  KeyboardID_NUMBERS_MINI,        // 14
  KeyboardID_QWERTY_AC_OFF_UPPER, // 15
  KeyboardID_TWITTER_LOWER,       // 16
  KeyboardID_TWITTER_UPPER,       // 17
  KeyboardID_URL_LOWER,           // 18
  KeyboardID_URL_UPPER,           // 19
  KeyboardID_PHONE_PAD,           // 20
  KeyboardID_PHONE_PAD_SYMBOLS,   // 21
  KeyboardID_EMAIL_LOWER,         // 22
  KeyboardID_EMAIL_UPPER,         // 23
  KeyboardID_NUMBER_OF_KEYBOARDS, // 24
  KeyboardID_INVALID
} KeyboardID;


typedef enum { // Copy of Engine's FLDictionaryChangeEvent
  DictionaryChangeEvent_ADD,
  DictionaryChangeEvent_REMOVE,
  DictionaryChangeEvent_WORD_AUTOLEARNED
} DictionaryChangeEvent;
