/*
	\file		protector.h
	
	\remarks	The Protector class is a Value* class that contains
				a list of ValueWrapper*'s that have been created to protect
				them during MAXScript garbage collection
*/

#ifndef		__PROTECTOR_H__
#define		__PROTECTOR_H__

applyable_class( Protector );
class Protector : public Value {
public:
	Protector();
	~Protector();

	classof_methods( Protector, Value );
	void		collect() { delete this; }
	void		gc_trace();
	Value*		get_property( Value** arg_list, int count );

	static void	protect( PyObject* );
	static void unprotect( PyObject* );
	static void init();
};

#endif		__PROTECTOR_H__