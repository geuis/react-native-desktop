/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <AppKit/AppKit.h>

#import "RCTComponent.h"

//TODO: let's try to eliminate this category if possible

@interface NSView (React) <RCTComponent>

- (NSArray<NSView *> *)reactSubviews;
- (NSView *)reactSuperview;

/**
 * Used by the UIIManager to set the view frame.
 * May be overriden to disable animation, etc.
 */
- (void)reactSetFrame:(CGRect)frame;

/**
 * Used to improve performance when compositing views with translucent content.
 */
- (void)reactSetInheritedBackgroundColor:(NSColor *)inheritedBackgroundColor;

/**
 * This method finds and returns the containing view controller for the view.
 */
- (NSViewController *)reactViewController;

/**
 * This method attaches the specified controller as a child of the
 * the owning view controller of this view. Returns NO if no view
 * controller is found (which may happen if the view is not currently
 * attached to the view hierarchy).
 */
- (void)reactAddControllerToClosestParent:(NSViewController *)controller;

/**
 * Responder overrides - to be deprecated.
 */
- (void)reactWillMakeFirstResponder;
- (void)reactDidMakeFirstResponder;
- (BOOL)reactRespondsToTouch:(NSEvent *)touch;

@end
