#include <spawn.h>
#include <objc/runtime.h>
#include <dlfcn.h>


@interface SigneUtilities : NSObject

@property (nonatomic, retain) NSMutableDictionary *commands;
@property (nonatomic, retain) NSMutableDictionary *commandKeys;
@property (nonatomic, assign) BOOL shouldContinueAfterAlert;

@property (nonatomic, assign) BOOL wifiEnabled;
@property (nonatomic, assign) BOOL bluetoothEnabled;
@property (nonatomic, assign) BOOL airplaneModeEnabled;
@property (nonatomic, assign) BOOL cellularEnabled;
+ (instancetype)sharedUtilities;

- (BOOL)keyHasCommand:(NSString *)key;
- (void)setCommandToRun:(NSString *)command forKey:(NSString *)key;
- (void)runCommand:(NSString *)commandName;
- (NSString *)getCommandForKey:(NSString *)key;
- (void)performCommandForKey:(NSString *)commandKey;
- (void)showAlertController:(NSString *)alertMessage selector:(SEL)method;


#pragma mark Commands

// System commands
- (void)sbreload;
- (void)respring;
- (void)enterSafeMode;
- (void)runUICache;

// Media commands
- (void)setWifiStatus;
- (void)setBTStatus;


@end

@interface SBWiFiManager : NSObject

+ (instancetype)sharedInstance;
- (void)setWiFiEnabled:(BOOL)arg1;
- (BOOL)wiFiEnabled;

@end

@interface BluetoothManager
-(id)sharedInstance;
-(void)setEnabled:(BOOL)enabled;
-(bool)enabled;

-(void)setPowered:(BOOL)powered;
-(bool)powered;

@end

@interface RadiosPreferences : NSObject
-(BOOL)airplaneMode;
-(void)setAirplaneMode:(BOOL)arg1;

@end

@interface VideosPlaybackSettings : NSObject
+(id)sharedSettings;
-(void)setCellularDataEnabled:(BOOL)arg1 ;
-(BOOL)isCellularDataEnabled;
@end

@interface SBAssistantController : NSObject
+(id)sharedInstance;
-(BOOL)handleSiriButtonDownEventFromSource:(int)arg1 activationEvent:(int)arg2;
-(void)handleSiriButtonUpEventFromSource:(int)arg1;
@end