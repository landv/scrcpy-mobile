//
//  UICommonUtils.h
//  scrcpy-ios
//
//  Created by Ethan on 26/2/23.
//

#ifndef UICommonUtils_h
#define UICommonUtils_h

#import <UIKit/UIKit.h>

static inline void ShowAlertFrom(UIViewController *fromController,
                                 NSString *message,
                                 UIAlertAction *okAction,
                                 UIAlertAction *cancelAction) {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Scrcpy Remote" message:message preferredStyle:(UIAlertControllerStyleAlert)];
    
    if (okAction) [alert addAction:okAction];
    if (cancelAction) [alert addAction:cancelAction];
    
    if (!okAction && !cancelAction) {
        [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:(UIAlertActionStyleCancel) handler:nil]];
    }
    [fromController presentViewController:alert animated:YES completion:nil];
}

static inline CVCreate *CreateDarkButton(NSString *title, id target, SEL action) {
    return CVCreate.UIButton.text(title)
        .boldFontSize(16)
        .size(CGSizeMake(0, 45))
        .textColor(UIColor.whiteColor)
        .backgroundColor(UIColor.blackColor)
        .cornerRadius(6)
        .click(target, action);
}

static inline CVCreate *CreateLightButton(NSString *title, id target, SEL action) {
    return CVCreate.UIButton.text(title)
        .boldFontSize(16)
        .size(CGSizeMake(0, 45))
        .textColor(UIColor.blackColor)
        .backgroundColor(UIColor.whiteColor)
        .border(UIColor.grayColor, 2.f)
        .cornerRadius(6)
        .click(target, action);
}

#endif /* UICommonUtils_h */
