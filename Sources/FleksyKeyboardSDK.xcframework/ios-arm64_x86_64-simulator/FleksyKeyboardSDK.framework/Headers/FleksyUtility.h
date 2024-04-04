//
//  FleksyUtility.h
//  FleksyFramework
//
//  Created by Tusi Chowdhury on 2014-10-22.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#ifndef FleksyiOS_FleksyUtility_h
#define FleksyiOS_FleksyUtility_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/**
 * A base class for various Utility catergories. Only global utility methods should live in the base class
 */
@interface FleksyUtility : NSObject

/**
 Get the default identifier of the app.

 @return NSString with the value of the identifier
 
 This tries to get the IDFA if possible. If not, it tries to get the `identifierForVendor`. As a last resource, it creates a UUID string.
 */
+ (NSString * _Nonnull)defaultIdentifier;

/// The IDFA or `nil` if not available.
+ (NSString * _Nullable)identifierForAdvertisers;

/// Returns a rect with the original size of the keyboard (see ``StyleConfiguration/KeyboardSize-swift.enum/original``).
+ (CGRect)getDefaultFleksyKeyboardSizeWithTraitCollection:(UITraitCollection *_Nonnull)traitCollection;

@end

#endif //  FleksyiOS_FleksyUtility_h
