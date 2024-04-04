//  PerformanceDelegate.h
//  FleksyKeyboardSDK
//
//  Copyright © 2023 Thingthing. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@protocol PerformanceDelegate <NSObject>

- (BOOL)performanceTrackingEnabled;
- (void)startEvent:(NSString *)name;
- (void)updateEvent:(NSString *)name withValue:(NSString *)value forAttribute:(NSString *)attribute;
- (void)incrementMetric:(NSString *)metricName forEvent:(NSString *)eventName;
- (void)endEvent:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
