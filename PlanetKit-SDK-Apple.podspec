Pod::Spec.new do |s|

  s.name = 'PlanetKit-SDK-Apple'
  s.version = '6.0.4'
  s.summary = 'PlanetKit iOS/macOS Framework'
  s.description = 'PlanetKit iOS/macOS Framework for Planet VoIP Service'
  
  s.homepage = 'https://docs.lineplanet.me'
  s.screenshots = 'https://docs.lineplanet.me/img/planet.png'
  
  s.license = { :type => 'Copyright', :text => <<-LICENSE
                Copyright (C) 2020-2025 LINE Plus Corp. All rights reserved.
                LICENSE
              }
  s.authors = { 'LINE Planet' => 'dl_next_voip@linecorp.com' }
  
  s.source = { :git => 'https://github.com/line/planet-kit-apple.git', :tag => s.version }
  s.vendored_frameworks = 'Frameworks/PlanetKit.xcframework'
  s.swift_version = '5.0'
  s.ios.deployment_target = '13.0'
  s.osx.deployment_target = '10.14.6'

end
