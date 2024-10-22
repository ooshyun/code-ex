import nested_class

nested_obj = nested_class.nestedClass()

# Set ex_map for a tag
nested_obj.ex_map["Scream"] = -1

# # Set ex_map for a tag
# nested_obj["Scream"] = -1

# Set ex_map for dict
nested_obj.ex_map = {"Scream": -1, "Music": 1}

# Get ex_map for a tag
print(nested_obj.ex_map["Scream"])  # Should print -1
print(nested_obj.ex_map["Music"])  # Should

# Get all sensitivities
print(nested_obj.ex_map)  # Should print the entire map
print(dict(nested_obj.ex_map))  # Should print the entire map
