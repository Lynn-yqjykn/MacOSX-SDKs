
/*
 *  CLHeading.h
 *  CoreLocation
 *
 *  Copyright 2008 Apple, Inc. All rights reserved.
 *
 */

#import <CoreLocation/CLAvailability.h>
#import <CoreLocation/CLLocation.h>
#import <Foundation/Foundation.h>

/*
 *  CLHeadingComponentValue
 *  
 *  Discussion:
 *    Type represents a geomagnetic value, measured in microteslas, relative to a device axis in three dimensional space.
 *
 */
typedef double CLHeadingComponentValue;

/*
 *  kCLHeadingFilterNone
 *  
 *  Discussion:
 *    Use as the headingFilter property for CLLocationManager. This indicates 
 *    to the heading service that no minimum movement filter is desired - ie, client will be informed
 *    of any movement.
 */
extern const CLLocationDegrees kCLHeadingFilterNone;

/*
 *  CLHeading
 *  
 *  Discussion:
 *    Represents a vector pointing to magnetic North constructed from axis component values x, y, and z. An accuracy of the heading calculation is also provided along with timestamp information.
 */
NS_CLASS_AVAILABLE(10_7, 3_0)
@interface CLHeading : NSObject <NSCopying, NSCoding>
{
@private
    id _internal;
}

/*
 *  magneticHeading
 *  
 *  Discussion:
 *    Represents the direction in degrees, where 0 degrees is magnetic North. The direction is referenced from the top of the device regardless of device orientation as well as the orientation of the user interface.
 *
 *  Range:
 *    0.0 - 359.9 degrees, 0 being magnetic North
 */
@property(readonly, nonatomic) CLLocationDirection magneticHeading;

/*
 *  trueHeading
 *  
 *  Discussion:
 *    Represents the direction in degrees, where 0 degrees is true North. The direction is referenced
 *    from the top of the device regardless of device orientation as well as the orientation of the
 *    user interface.
 *
 *  Range:
 *    0.0 - 359.9 degrees, 0 being true North
 */
@property(readonly, nonatomic) CLLocationDirection trueHeading;

/*
 *  headingAccuracy
 *  
 *  Discussion:
 *    Represents the maxiumum deviation of where the magnetic heading may differ from the actual geomagnetic heading in degrees. A negative value indicates an invalid heading.
 */
@property(readonly, nonatomic) CLLocationDirection headingAccuracy;

/*
 *  x
 *  
 *  Discussion:
 *    Returns a raw value for the geomagnetism measured in the x-axis.
 *
 */
@property(readonly, nonatomic) CLHeadingComponentValue x;

/*
 *  y
 *  
 *  Discussion:
 *    Returns a raw value for the geomagnetism measured in the y-axis.
 *
 */
@property(readonly, nonatomic) CLHeadingComponentValue y;

/*
 *  z
 *  
 *  Discussion:
 *    Returns a raw value for the geomagnetism measured in the z-axis.
 *
 */
@property(readonly, nonatomic) CLHeadingComponentValue z;

/*
 *  timestamp
 *  
 *  Discussion:
 *    Returns a timestamp for when the magnetic heading was determined.
 */
@property(readonly, nonatomic) NSDate *timestamp;

/*
 *  description
 *  
 *  Discussion:
 *    Returns a string representation of the heading.
 */
- (NSString *)description;

@end
