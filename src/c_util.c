/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*  This file is part of cstl library
*  Copyright (C) 2011 Avinash Dongre ( dongre.avinash@gmail.com )
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in
*  all copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
*  THE SOFTWARE.
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/

#include "c_lib.h"
#include <string.h>
#include <stdlib.h>

void
cstl_copy(void* destination, void* source, size_t size) {
    memcpy((char*)destination, source, size);
}

void
cstl_get(void* destination, void* source, size_t size) {
    memcpy(destination, (char*)source, size);
}

struct cstl_object*
new_cstl_object(void* inObject, size_t obj_size) {
    struct cstl_object* tmp = (struct cstl_object*)malloc(sizeof(struct cstl_object));
    if (!tmp)
        return (struct cstl_object*)0;
    tmp->size = obj_size;
    tmp->raw_data = (void*)malloc(obj_size);
    if (!tmp->raw_data) {
        free(tmp);
        return (struct cstl_object*)0;
    }
    memcpy(tmp->raw_data, inObject, obj_size);
    return tmp;
}

cstl_error
get_raw_cstl_object(struct cstl_object *inObject, void**elem) {
    *elem = (void*)malloc(inObject->size);
    if (!*elem)
        return CSTL_ELEMENT_RETURN_ERROR;
    memcpy(*elem, inObject->raw_data, inObject->size);

    return CSTL_ERROR_SUCCESS;
}

void
replace_raw_cstl_object(struct cstl_object* current_object, void* elem, size_t elem_size) {
    free(current_object->raw_data);
    current_object->raw_data = (void*)malloc(elem_size);
    memcpy(current_object->raw_data, elem, elem_size);
}

void
delete_cstl_object(struct cstl_object* inObject) {
    if (inObject) {
        free(inObject->raw_data);
        free(inObject);
    }
}

char*
cstl_strdup(char *ptr) {
#ifdef WIN32
    return _strdup(ptr);
#else
    return strdup(ptr);
#endif
}
