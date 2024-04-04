//
//  FleksyPullDownViewController.h
//  FleksyiOS
//
//  Created by Ben Pious on 7/6/15.
//  Copyright (c) 2015 Thingthing, Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FleksyViewControllerPresenter.h"

@interface FleksyPullDownViewController : UIViewController <UIScrollViewDelegate>

- (instancetype)initWithPullDownGestureEnabled:(BOOL)allowPullDownGesture;

@property (nonatomic, weak) id<FleksyViewControllerPresenter> presenter;
@property (nonatomic, readonly) BOOL allowsPullDownGesture;
- (void)addPullDownGestureRecognizerToView:(UIView *)view;
- (void)pullDownGestureOnGoing; // override in case you want to get this
- (void)pullDownGestureEnded; // override in case you want to get the Ended gesture
@end
