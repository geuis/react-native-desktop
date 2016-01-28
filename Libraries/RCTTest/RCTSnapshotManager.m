/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import "RCTSnapshotManager.h"

@interface RCTSnapshotView : NSView

@property (nonatomic, copy) RCTDirectEventBlock onSnapshotReady;
@property (nonatomic, copy) NSString *testIdentifier;

@end

@implementation RCTSnapshotView

- (void)setTestIdentifier:(NSString *)testIdentifier
{
  if (![_testIdentifier isEqualToString:testIdentifier]) {
    _testIdentifier = [testIdentifier copy];
    dispatch_async(dispatch_get_main_queue(), ^{
      if (self.onSnapshotReady) {
        self.onSnapshotReady(@{@"testIdentifier" : self.testIdentifier});
      }
    });
  }
}

@end


@implementation RCTSnapshotManager

RCT_EXPORT_MODULE()

<<<<<<< HEAD
- (NSView *)view {
=======
- (UIView *)view
{
>>>>>>> ae45d8bd4cc7b0fc810c3f21dcf2c7188ae3097d
  return [RCTSnapshotView new];
}

RCT_EXPORT_VIEW_PROPERTY(testIdentifier, NSString)
RCT_EXPORT_VIEW_PROPERTY(onSnapshotReady, RCTDirectEventBlock)

@end
