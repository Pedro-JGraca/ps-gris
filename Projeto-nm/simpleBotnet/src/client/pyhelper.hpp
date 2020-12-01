#ifndef PYHELPER_HPP
#define PYHELPER_HPP

#include <iostream>
#include <exception>
#include <string>
#include <Python.h>

using namespace std;


class CPyInstance
{
public:
	CPyInstance()
	{
		Py_Initialize();
        //allows import on same directory
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append(\".\")");   
	}
	CPyInstance(char *path)
	{
		Py_Initialize();
        //allows import on same directory
        PyRun_SimpleString("import sys");
        PyRun_SimpleString( 
			(std::string("sys.path.append(\"")+path+"\")" ).c_str()
			);   
	}

	~CPyInstance()
	{
		Py_Finalize();
	}
};


class CPyObject
{
private:
	PyObject *p;
public:
	CPyObject() : p(NULL)
	{}

	CPyObject(PyObject* _p)
	{
		if (!_p)
		{
            throw std::runtime_error("PyObject returned null. aborting");
        }
		p=_p;
	}

	
	~CPyObject()
	{
		Release();
	}

	PyObject* getObject()
	{
		return p;
	}

	PyObject* setObject(PyObject* _p)
	{
		if (!_p)
		{
            throw std::runtime_error("PyObject returned null. aborting");
        }
		return (p=_p);
	}

	PyObject* AddRef()
	{
		if(p)
		{
			Py_INCREF(p);
		}
		return p;
	}

	void Release()
	{
		if(p)
		{
			Py_DECREF(p);
		}

		p= NULL;
	}

	PyObject* operator ->()
	{
		return p;
	}

	bool is()
	{
		return p ? true : false;
	}

	operator PyObject*()
	{
		return p;
	}

	PyObject* operator = (PyObject* pp)
	{
		
        if (!pp)
		{
            throw std::runtime_error("PyObject returned null. aborting");
        }
		p = pp;
		return p;
	}

	operator bool()
	{
		return p ? true : false;
	}
};


#endif