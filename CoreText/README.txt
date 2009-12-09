The headers for CoreText is not open source, so they are not placed here.
Nevertheless, you can make a copy from Mac OS X:

 (1) cp /System/Library/Frameworks/ApplicationServices.framework/Frameworks/CoreText.framework/Headers/* .
 (2) Apply the following patch:

--- /System/Library/Frameworks/ApplicationServices.framework/Frameworks/CoreText.framework/Headers/CTFont.h	2009-07-16 13:49:43.000000000 +0800
+++ CTFont.h	2009-12-10 02:56:49.000000000 +0800
@@ -19,7 +19,6 @@
 
 #include <CoreText/CTFontDescriptor.h>
 
-#include <ATS/ATSTypes.h>
 #include <CoreGraphics/CGFont.h>
 #include <CoreGraphics/CGPath.h>
 
@@ -1059,6 +1058,7 @@
     const CGAffineTransform     *matrix,
     CTFontDescriptorRef         attributes ) AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;
 
+#if 0
 /*!
     @function   CTFontGetPlatformFont
     @abstract   Returns the ATSFontRef and attributes.
@@ -1098,6 +1098,7 @@
     CGFloat                     size,
     const CGAffineTransform     *matrix,
     CTFontDescriptorRef         attributes ) AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;
+#endif
 
 /*!
     @function   CTFontCreateWithQuickdrawInstance

