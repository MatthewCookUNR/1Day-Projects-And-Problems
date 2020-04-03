const _ = {
  //Returns number if it is within boundaries
  //Else, it returns lowerBound if lower
  //or upperBound if higher
  clamp(number, lowerBound, upperBound) {
    /* Alternate Solution
    if(number > lowerBound && number < upperBound) {
      return number;
    }
    else if (number < lowerBound) {
      return lowerBound;
    }
    else {
      return upperBound;
    }
    */

    //Ex: Lets say we called clamp(5, 6, 10)
    //Line below results in max(5, 6), which is 6 since 5 
    //which is correct since 5 is outside lower bound of 6
    let clamped = Math.max(number, lowerBound);
    clamped = Math.min(clamped, upperBound);
    return clamped;
  },
  //Checks if number is in range
  inRange(number, start, end) {

    //Case end is not specified
    if (end === undefined) {
      end = start;
      start = 0;
    }
    //If start is past end we swap them
    if(start > end) {
      let temp = end;
      end = start;
      start = temp;
    }
    //Returns true if number is within range
    if(number > start && number < end) {
      return true;
    }
    else {
      return false;
    }
  }, 
  //Splits string into words using ' ' as delimeter
  words(myString) {
    strArray = myString.split(' ');
    return strArray;
  }, 
  //Adds padding until string is at given length
  //If odd number needing, padding is added to the end
  pad(myString, length) {

    //Returns string if given length is smaller than
    //strings original length
    if (length <= myString.length) {
      return myString;
    }

    //Start padding is alway even
    const startPad = Math.floor((length - myString.length)/2);
    const endPad = length - myString.length - startPad;
    myString = " ".repeat(startPad) + myString;
    myString = myString + " ".repeat(endPad);
    return myString;
  }, 
  //Checks to see if object has key (not nested search)
  has(object, key) {
    if(object[key] !== undefined) {
      return true;
    }
    return false;
  }, 
  //Keys become values and vice versa in the given object
  invert(object) {
    let invertObj = {};
    for(const property in object) {
      invertObj[object[property].toString()] = property;
    }
    return invertObj;
  }, 
  //Finds first key in object that passes given truthy function
  //Note: No guarantee of order
  findKey(object, predicate) {
    for (let key in object) {
      if(predicate(object[key])) {
        return key;
      }
    }
    return undefined;
  }, 
  //Drops given number of elements from beginning of array
  drop(array, dropNum) {
    if(dropNum === undefined) {
      dropNum = 1;
    }
    newArray = array.slice(dropNum, array.length);
    return newArray;
  },
  //Drops elements from beginning of array until inputted
  //predicate function returns false
  dropWhile(array, predicate) {
    let dropNum = 0;
    for(let i = 0; i < array.length; i++) {
      if(predicate(array[i], i, array))
      {
        dropNum++;
      }
      else {
        break;
      }
    }
    return array.slice(dropNum, array.length);
  }, 
  //Seperates array into array of "chunk" arrays
  chunk(array, size=1) {
    let chunkyArray = [];
    for(let i = 0; i < array.length; i += size)
    {
      let arrayChunk = array.slice(i, i+size);
      chunkyArray.push(arrayChunk);
    }
    return chunkyArray;
  }
};