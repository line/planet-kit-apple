//
//  PlanetKitAudioControl.h
//  PlanetKit+iOS
//
//  Created by LINER on 2020/03/16.
//  Copyright © 2020 LINE Corp. All rights reserved.
//

#ifndef PlanetKitAudioControl_h
#define PlanetKitAudioControl_h


typedef NS_OPTIONS(int, PlanetKitAudioMixFlag)
{
    PlanetKitAudioMixFlagRX   = 0x01,
    PlanetKitAudioMixFlagTX   = 0x02,
    PlanetKitAudioMixFlagRXTX = (PlanetKitAudioMixFlagRX | PlanetKitAudioMixFlagTX),

    PlanetKitAudioMixFlagMuteRXDuringTXMuted = 0x04,
};

@protocol PlanetKitAudioMixHandle <NSObject>

@property(nonatomic, copy, readonly, nullable)      NSString        *filePath;
@property(nonatomic, readonly)                      PlanetKitAudioMixFlag  flags;
@property(nonatomic, readonly)                      int              loopCount;
@property(nonatomic, readonly, getter=isSolo)       BOOL             solo;

@property(nonatomic, readonly, getter=isFinishedRX) BOOL             finishedRX;
@property(nonatomic, readonly, getter=isFinishedTX) BOOL             finishedTX;

@property(nonatomic, assign, getter=isEnabled)      BOOL             enabled;

@property(nonatomic, copy, nullable) void (^completionBlock)(id<PlanetKitAudioMixHandle>_Nonnull, PlanetKitAudioMixFlag);

- (void)stop;

@end

@interface PlanetKitAudioControl : NSObject
- (void)prepare;
- (void)setup;
- (void)start;
- (void)reset;

- (void)play;
@end

#endif /* PlanetKitAudioControl_h */
