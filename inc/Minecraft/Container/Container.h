// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <deque>
#include <functional>
#include <string>
#include <unordered_set>
#include <vector>

// class std::vector< ItemStack   ,std::allocator< ItemStack   > >;
// class std::vector< ItemStack,std::allocator< ItemStack> >;
class ContainerContentChangeListener;
class ItemDescriptor;
class BlockSource;
class Vec3;
class ItemStack;
class CompoundTag;
class ItemInstance;
// struct std::string;
enum ContainerType;
class Player;
class ContainerSizeChangeListener;

class Container {
 public:
  static const int LARGE_MAX_STACK_SIZE;
  static const int DEFAULT_CONTAINER_SIZE;
  static const int INVALID_SLOT;

 protected:
  ContainerType mContainerType;
  std::unordered_set<ContainerContentChangeListener *,
                     std::hash<ContainerContentChangeListener *>,
                     std::equal_to<ContainerContentChangeListener *>,
                     std::allocator<ContainerContentChangeListener *> >
      mContentChangeListeners;
  std::unordered_set<ContainerSizeChangeListener *,
                     std::hash<ContainerSizeChangeListener *>,
                     std::equal_to<ContainerSizeChangeListener *>,
                     std::allocator<ContainerSizeChangeListener *> >
      mSizeChangeListeners;
  std::deque<std::function<void(Container &, int, const ItemStack &,
                                const ItemStack &)>,
             std::allocator<std::function<void(
                 Container &, int, const ItemStack &, const ItemStack &)> > >
      mTransactionContextStack;
  std::string mName;
  bool mCustomName;
  static const BidirectionalUnorderedMap<ContainerType, std::string>containerTypeMap;

 public:
  virtual ~Container();
  virtual void init();
  virtual void addContentChangeListener(ContainerContentChangeListener *);
  virtual void removeContentChangeListener(ContainerContentChangeListener *);
  virtual const ItemStack &getItem(int) const = 0;
  virtual bool hasRoomForItem(const ItemStack &);
  virtual void addItem(ItemStack &);
  virtual bool addItemToFirstEmptySlot(ItemStack &);
  virtual void setItem(int, const ItemStack &) = 0;
  virtual void removeItem(int, int);
  virtual void removeAllItems();
  virtual void dropContents(BlockSource &, const Vec3 &, bool);
  virtual int getContainerSize() const = 0;
  virtual int getMaxStackSize() const = 0;
  virtual void startOpen(Player &) = 0;
  virtual void stopOpen(Player &) = 0;
  virtual std::vector<ItemStack, std::allocator<ItemStack> > getSlotCopies()
      const;
  virtual const std::vector<ItemStack, std::allocator<ItemStack> > *getSlots()
      const;
  virtual int getItemCount(const ItemDescriptor &);
  virtual int getItemCount(const ItemStack &);
  virtual int findFirstSlotForItem(const ItemStack &) const;
  virtual bool canPushInItem(BlockSource &, int, int,
                             const ItemInstance &) const;
  virtual bool canPullOutItem(BlockSource &, int, int,
                              const ItemInstance &) const;
  virtual void setContainerChanged(int);
  virtual void setContainerMoved();
  virtual void setCustomName(const std::string &);
  virtual bool hasCustomName() const;
  virtual void readAdditionalSaveData(const CompoundTag &);
  virtual void addAdditionalSaveData(CompoundTag &);
  virtual void createTransactionContext(class std::function<void(Container&, const ItemStack&, const ItemStack&)>, std::function<void(void)>);
  virtual void triggerTransactionChange(int, const ItemStack &,
                                        const ItemStack &);

  // Begin Non-Virtual Functions
  Container(ContainerType);
  int getRedstoneSignalFromContainer();
  static ContainerType getContainerTypeId(const std::string &);
};