//
//  PhotoPreview.h
//  CameraOverlayView
//
//  Created by B.H.Liu appublisher on 12-2-15.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PhotoPreview;

@protocol PhotoPreviewDelegate <NSObject>

- (void)thumbnailTapped;
- (void)previewClosed;
- (void)imageForUse:(UIImage*)image;

@end

@interface PhotoPreview : UIView <UIActionSheetDelegate>
{
    UIImage *_image;
	UIButton *_imageButton;
	UIButton *_thumbnailButton;
	id _delegate;
}

@property (nonatomic,retain) UIImage *image;
@property (nonatomic,assign) id<PhotoPreviewDelegate>delegate;

- (void)hideThumbnail;
- (void)hideThumbnailAfterDelay:(CGFloat)delay;
- (void)showThumbnail:(UIImage *)newImage;
- (UIImage*)generateThumbnail:(UIImage*)source;
- (void)generateAndShowThumbnail:(UIImage*)source;
- (void)hidePreviewImage;

@end
