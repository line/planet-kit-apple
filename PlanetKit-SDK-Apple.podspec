Pod::Spec.new do |s|

  s.name = 'PlanetKit-SDK-Apple'
  s.version = '5.3.6'
  s.summary = 'PlanetKit iOS/macOS/tvOS Framework'
  s.description = 'PlanetKit iOS/macOS/tvOS Framework for Planet VoIP Service'
  
  s.homepage = 'https://docs.lineplanet.me'
  s.screenshots = 'https://docs.lineplanet.me/img/planet.png'
  
  s.license = { :type => 'Copyright', :text => <<-LICENSE
                Copyright (C) 2020-2024 LINE Corp. All rights reserved.
                LICENSE
              }
  s.authors = { 'LINE Planet' => 'dl_next_voip@linecorp.com' }
  
  s.source = { :git => 'https://github.com/line/planet-kit-apple.git', :tag => s.version }
  s.vendored_frameworks = 'Frameworks/PlanetKit.xcframework'
  s.swift_version = '5.0'
  s.ios.deployment_target = '12.0'
  s.osx.deployment_target = '10.14.6'
  s.tvos.deployment_target = '12.0'

end
