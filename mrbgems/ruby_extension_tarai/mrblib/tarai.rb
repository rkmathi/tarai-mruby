class RTarai
  def self.tak(x, y, z)
    if x <= y
      return z
    else
      tak(tak(x-1, y, z), tak(y-1, z, x), tak(z-1, x, y))
    end
  end

  def self.tarai(x, y, z)
    if x <= y
      return y
    else
      tarai(tarai(x-1, y, z), tarai(y-1, z, x), tarai(z-1, x, y))
    end
  end
end
