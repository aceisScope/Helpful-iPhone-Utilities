//
//  CustomCameraViewController.h
//  CameraOverlayView
//
//  Created by B.H.Liu appublisher on 12-2-15.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APFullScreenCameraPicker.h"
#import "PhotoPreview.h"

@protocol CustomCameraDelegate <NSObject>

- (void)customCameraDidFinished:(UIImage*)image;
- (void)customCameraDidCancelled;

@end

@interface CustomCameraViewController : UIViewController<UIImagePickerControllerDelegate, UINavigationControllerDelegate,APFullScreenCameraPickerDelegate,PhotoPreviewDelegate> 
{
    APFullScreenCameraPicker *_camera;
    PhotoPreview *_preView;
    UIView *_overlayView;
    BOOL  _cameraMode;
    CGPoint _startTouchPosition;
}

@property (nonatomic, retain) APFullScreenCameraPicker *camera;
@property (nonatomic,retain) PhotoPreview *preView;
@property (nonatomic, retain) UIView *overlayView;
@property (assign) BOOL cameraMode;
@property (nonatomic) CGPoint startTouchPosition;
@property (nonatomic,assign) id<CustomCameraDelegate>delegate;

- (void)initCamera;
//- (void)toggleAugmentedReality;
- (void)startCamera;
- (void)onSingleTap:(UITouch*)touch;
- (void)onDoubleTap:(UITouch*)touch;
- (void)onSwipeUp;
- (void)onSwipeDown;
- (void)onSwipeLeft;
- (void)onSwipeRight;


@end
