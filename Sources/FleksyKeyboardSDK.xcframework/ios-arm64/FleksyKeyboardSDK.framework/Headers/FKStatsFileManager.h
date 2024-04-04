//
//  FKStatsFileManager.h
//  FleksyKit
//
//  Created by Xavier Farrarons Clusella on 05/04/2018.
//  Copyright © 2018 Thingthing, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  In charge of managing the lenght of the stats file, what we store and how
 *  - to make it easy to upload
 */
@interface FKStatsFileManager : NSObject

+ (NSString*) getCurrentFolder;

/// Encrypts and stores the passed generic data into a file. Returns the path of the file where the encrypted generic data is to be stored.
/// @param contents The data to store into an encrypted file.
/// @param key The key used to encrypt the data.
+ (NSString *)storeGenericContents:(NSString*) contents withKey:(nullable NSString*) key;

@end

NS_ASSUME_NONNULL_END
