//
//  SDLUIKitDelegate+Extend.m
//  scrcpy-ios
//
//  Created by Ethan on 2022/6/11.
//

#import "SDLUIKitDelegate+Extend.h"

@implementation SDLUIKitDelegate (Extend)

-(void)applicationDidEnterBackground:(UIApplication *)application {
    // For more time execute in background
    static void (^beginTaskHandler)(void) = nil;
    beginTaskHandler = ^{
        [UIApplication.sharedApplication beginBackgroundTaskWithName:@"scrcpy" expirationHandler:beginTaskHandler];
    };
    beginTaskHandler();
}

-(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options
{
    NSLog(@"> Received URL: %@", url.absoluteURL);
    // Post connect
    [NSNotificationCenter.defaultCenter postNotificationName:ScrcpyConnectWithSchemeNotification object:nil userInfo:@{
        ScrcpyConnectWithSchemeURLKey : url
    }];
    return YES;
}

@end