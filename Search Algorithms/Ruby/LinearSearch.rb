def linear_search(array, key)
  if array.index(key).nil?
    return -1
  else
    return "#{key} at index #{array.index(key)}"
  end
end


arr = [7, 6, 25, 19, 8, 14, 3, 16, 2, 0]
key = 3
p linear_search(arr, key)
