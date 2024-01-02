//
//  BCCUtils.h
//  BroadcastClient
//
//  Created by LinePlus on 2015. 11. 16..
//  Copyright © 2015년 LINE. All rights reserved.
//

//#if DEBUG_MENU_ENABLED

#define ColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define BCCLocalizedString(key) NSLocalizedStringFromTable(key, @"Localizable", nil)
#define BCCDocumentURL() [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] lastObject];

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#define SWAP(x, y, T)	{ T SWAP = x; x = y; y = SWAP; }

static NSString *const BCCUtilsKeyWWANSent = @"WWANSent";
static NSString *const BCCUtilsKeyWWANReceived = @"WWANReceived";
static NSString *const BCCUtilsKeyWiFiSent = @"WiFiSent";
static NSString *const BCCUtilsKeyWiFiReceived = @"WiFiReceived";

@interface BCCHardware: NSObject
@property (strong, nonatomic) NSString* name;
@property (assign, nonatomic) NSInteger major;
@property (assign, nonatomic) NSInteger minor;
@end


@interface BCCUtils: NSObject

+ (BCCUtils *)sharedInstance NS_SWIFT_NAME(shared());

@property (class, readonly) NSString *thumbnailDirectoryPath;

+ (BOOL)isRecorderAlreadyLaunchedOnce;

+ (uint64_t)getFreeDiskspace;
- (Float32)getCpuUsage;
- (uint64_t)getMemoryUsage;
- (NSDictionary*)getNetworkUsage;

// Get device model name
+ (NSString*)platform;
+ (BCCHardware*)platformInfo;

+ (uint64_t)getTickCount;

@end

extern void dispatch_repeated(double intervalInSeconds, dispatch_queue_t queue, void(^work)(BOOL *stop));
//#endif
