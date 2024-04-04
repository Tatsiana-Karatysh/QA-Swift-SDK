//
//  FleksyCursorControllable.h
//  FleksyiOS
//
//  Created by Ben Pious on 11/9/15.
//  Copyright © 2015 Thingthing, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol FleksyCursorControllable <NSObject>

@property (nonatomic) BOOL isShowingCursorControl;

@end

@protocol FleksyCursorControlDelegate <NSObject>

/// The height of the keyboard container view, meaning the view containing only the keyboard keys and buttons, disregarding the top bar and FleksyApp views.
@property (assign, nonatomic, readonly) CGFloat keyboardContainerHeight;

@end
