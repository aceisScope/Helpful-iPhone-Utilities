//
//  ViewController.m
//  CameraOverlayView
//
//  Created by B.H.Liu appublisher on 12-2-15.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import "ViewController.h"


@implementation ViewController

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    UIButton *button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [button setTitle:@"take a photo" forState:UIControlStateNormal];
    button.frame = CGRectMake(10, 10, 200, 40);
    [self.view addSubview:button];
    [button addTarget:self action:@selector(takePhoto) forControlEvents:UIControlEventTouchUpInside];
}

- (void)takePhoto
{
    CustomCameraViewController *viewController = [[[CustomCameraViewController alloc] initWithNibName:nil bundle:nil] autorelease];
    [self presentModalViewController:viewController animated:YES];
    viewController.delegate = self;
}

- (void)customCameraDidCancelled
{
    [self dismissModalViewControllerAnimated:YES];
}

- (void)customCameraDidFinished:(UIImage *)image
{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:nil message:@"Photo Taken!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
    [alert show];
    [alert release];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

@end
