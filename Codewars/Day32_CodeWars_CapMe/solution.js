return names.map(name => {
    if (!name) { // Handle empty strings to avoid errors
      return "";
    }
    const firstLetter = name.charAt(0).toUpperCase();
    const restOfName = name.slice(1).toLowerCase();
    return firstLetter + restOfName;
  });


