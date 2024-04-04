//  FleksyAPIManagerDelegate.h
//  FleksyKeyboardSDK
//
//  Copyright © 2023 Thingthing. All rights reserved.
//

#import "FKEnums.h"
#import "FleksyKeyboardDisplayStateInfoProvider.h"

@class KeyStrokeEventPayloadCppWrapper;
@class DeleteEventPayloadCppWrapper;
@class KeyPlaneEventPayloadCppWrapper;
@class WordEventPayloadCppWrapper;
@class SwipeEventPayloadCppWrapper;
@class SessionUpdateEventPayloadCppWrapper;
@class StressUpdateEventPayloadCppWrapper;

typedef enum {
  FSErrorAPINoResource,
  FSErrorAPIGeneric,
  FSErrorAPITypingRelated
} FSAPIManagerErrorCode;


@protocol FleksyEngineButtonHandler <NSObject>

- (BOOL)buttonPressed:(ButtonType)button;

@end

@interface FleksyExternalEditorState : NSObject

@property (nonatomic, copy) NSString *text;
@property (nonatomic, assign) NSRange selection;

@end

@protocol FleksyAPIManagerDelegate <FleksyKeyboardDisplayStateInfoProvider, FleksyEngineButtonHandler>

- (void)setSelection:(NSRange) range;
- (FleksyExternalEditorState *)keyboardState;
- (BOOL)replaceComposingText:(NSString *)someText;
- (void)storeComposingRangeStart:(int) start end:(int) end;
- (void)messageReceivedFromAPI:(MessageType)type message:(NSString *) message;
- (void)dictionaryModifiedFromAPIWithEvent:(DictionaryChangeEvent)event word:(NSString *)word;
- (void)selectedSuggestionsChangedFromAPI:(int)selectedIndex;
- (void)sendSpeakFromAPI:(NSString *)text;
- (void)requestLayoutChangeFromEngine:(KeyboardID)keyboardID;
- (void)typeChanged:(ButtonType)type
   forButtonsOfType:(ButtonType)oldType;
- (void)respondToAPIError:(FSAPIManagerErrorCode)error;
- (void)highlightsReceivedFromEngine:(NSString *) stringJson;
- (void)nextWordPredictionsReceivedFromEngine:(NSArray<NSString *> *)predictions predictionTypes:(NSArray <NSNumber *> *)predictionTypes;
- (void)japanesePredictionsReceivedFromEngine:(NSArray<NSString *> *)predictions;
- (void)onDelete;
- (void)onReportCorrectionCounts:(NSString*) langCode
                            none:(NSUInteger) none missSpace:(NSUInteger) missSpace missTypedSpace:(NSUInteger)cvbSpace
                      eliminated:(NSUInteger)elim transposition:(NSUInteger)trans
                         missing:(NSUInteger) missing controller:(NSUInteger) tc;
@property (nonatomic, readonly) NSRange composingRegion;

// Event-based data capture callbacks

- (void)onDataCaptureKeyStrokeEventWithPayload:(KeyStrokeEventPayloadCppWrapper *)payload;
- (void)onDataCaptureDeleteEventWithPayload:(DeleteEventPayloadCppWrapper *)payload;
- (void)onDataCaptureKeyPlaneEventWithPayload:(KeyPlaneEventPayloadCppWrapper *)payload;
- (void)onDataCaptureWordEventWithPayload:(WordEventPayloadCppWrapper *)payload;
- (void)onDataCaptureSwipeEventWithPayload:(SwipeEventPayloadCppWrapper *)payload;
- (void)onDataCaptureSessionUpdateEventWithPayload:(SessionUpdateEventPayloadCppWrapper *)payload;
- (void)onDataCaptureStressUpdateEventWithPayload:(StressUpdateEventPayloadCppWrapper *)payload;

@end
