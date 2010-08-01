#!/usr/bin/env ruby

#            find this                     write this after
# |------------------------------------|------------------------|
# [00 00 00 14 76 6D 68 64 00 00 00 01] [01 04 FF FF FF FF FF FF]
#
# 
USAGE = %{
  
qt-straightalpha is a ruby script to patch an mp4 file suffering from darkness when viewed with quicktime/safari on PC.
Your movie file will be patched inplace, so back it up before use.
  
USAGE: ./qt-straightalpha movie.mp4

}

if ARGV.size < 1
  puts USAGE
  exit
end
SEARCH = %w(00 00 00 14 76 6D 68 64 00 00 00 01)
PATCH = %w(01 04 FF FF FF FF FF FF)

def process(bytes)
  b = bytes.unpack('H2')[0]
  @state ||= 0
  if @state < SEARCH.size
    @state += (b == SEARCH[@state].downcase ? 1 : 0) 
  end
  @state == SEARCH.size
end


File.open(ARGV[0],'r+') do |mp4|  
  while (bytes = mp4.read(1))
    if process(bytes)
      puts "Patching..."
      mp4.write PATCH.pack('H2H2H2H2H2H2H2H2')
      break
    end
  end
end