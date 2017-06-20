template<class T>
class RCIPtr {
	public:
		RCIPtr(T* realPtr = 0);
		RCIPtr(const RCIPtr& rhs);
		~RCIPtr();
		RCIPtr& operator=(const RCIPtr& rhs);
		const T* operator->() const; // see below for an
		T* operator->(); // explanation of why
		const T& operator*() const; // these functions are
		T& operator*(); // declared this way
	private:
		struct CountHolder: public RCObject {
			~CountHolder() { delete pointee; }
			T *pointee;
		};
	CountHolder *counter;
	void init();
	void makeCopy(); // see below
};

template<class T>
void RCIPtr<T>::init()
{
	if (counter->isShareable() == false) {
		T *oldValue = counter->pointee;
		counter = new CountHolder;
		counter->pointee = new T(*oldValue);
	}
	counter->addReference();
}

template<class T>
RCIPtr<T>::RCIPtr(T* realPtr)
: counter(new CountHolder)
{
	counter->pointee = realPtr;
	init();
}

template<class T>
RCIPtr<T>::RCIPtr(const RCIPtr& rhs)
: counter(rhs.counter)
{ init(); }

template<class T>
RCIPtr<T>::~RCIPtr()
{ counter->removeReference(); }

template<class T>
RCIPtr<T>& RCIPtr<T>::operator=(const RCIPtr& rhs)
{
	if (counter != rhs.counter) {
		counter->removeReference();
		counter = rhs.counter;
		init();
	}
	return *this;
}

template<class T> // implement the copy
void RCIPtr<T>::makeCopy() // part of copy-on-
{ // write (COW)
	if (counter->isShared()) {
		T *oldValue = counter->pointee;
		counter->removeReference();
		counter = new CountHolder;
		counter->pointee = new T(*oldValue);
		counter->addReference();
	}
}

template<class T> // const access;
const T* RCIPtr<T>::operator->() const // no COW needed
{ return counter->pointee; }

template<class T> // non-const
T* RCIPtr<T>::operator->() // access; COW
{ makeCopy(); return counter->pointee; } // needed

template<class T> // const access;
const T& RCIPtr<T>::operator*() const // no COW needed
{ return *(counter->pointee); }

template<class T> // non-const
T& RCIPtr<T>::operator*() // access; do the
{ makeCopy(); return *(counter->pointee); } // COW thing


class Widget {
	public:
		Widget(int size);
		Widget(const Widget& rhs);
		~Widget();
		Widget& operator=(const Widget& rhs);
		void doThis();
		int showThat() const;
};

class RCWidget {
	public:
		RCWidget(int size): value(new Widget(size)) {}
		void doThis() { value->doThis(); }
		int showThat() const { return value->showThat(); }
	private:
		RCIPtr<Widget> value;
};