//
//  JCViewController.m
//  JCLog
//
//  Created by JC on 05/17/2018.
//  Copyright (c) 2018 lswh. All rights reserved.
//

#import "JCViewController.h"
#import <JCLog/JCLog.h>

@interface JCViewController ()

@end

@implementation JCViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    JCLogInfo(@"test");
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
