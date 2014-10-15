AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS)

if USE_LIBSECP256K1
secp256k1/libsecp256k1.la: $(wildcard secp256k1/src/*) $(wildcard secp256k1/include/*)
	@$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)
endif

if EMBEDDED_LEVELDB
LEVELDB_CPPFLAGS += -I$(srcdir)/leveldb/include
LEVELDB_CPPFLAGS += -I$(srcdir)/leveldb/helpers/memenv
LIBLEVELDB += $(builddir)/leveldb/libleveldb.a
LIBMEMENV  += $(builddir)/leveldb/libmemenv.a

# NOTE: This dependency is not strictly necessary, but without it make may try to build both in parallel, which breaks the LevelDB build system in a race
$(LIBLEVELDB): $(LIBMEMENV)

$(LIBLEVELDB) $(LIBMEMENV):
	@echo "Building LevelDB ..." && $(MAKE) -C $(@D) $(@F) CXX="$(CXX)" \
	  CC="$(CC)" PLATFORM=$(TARGET_OS) AR="$(AR)" $(LEVELDB_TARGET_FLAGS) \
          OPT="$(CXXFLAGS) $(CPPFLAGS)"
endif

DIAMOND_CONFIG_INCLUDES=-I$(builddir)/config
DIAMOND_INCLUDES=-I$(builddir) -I$(builddir)/obj $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

if USE_LIBSECP256K1
DIAMOND_INCLUDES += -I$(srcdir)/secp256k1/include
endif

LIBDIAMOND_SERVER=libdiamond_server.a
LIBDIAMOND_WALLET=libdiamond_wallet.a
LIBDIAMOND_COMMON=libdiamond_common.a
LIBDIAMOND_CLI=libdiamond_cli.a
LIBDIAMOND_UTIL=libdiamond_util.a
LIBDIAMOND_CRYPTO=crypto/libdiamond_crypto.a
LIBDIAMOND_UNIVALUE=univalue/libdiamond_univalue.a
LIBDIAMONDQT=qt/libdiamondqt.a

noinst_LIBRARIES = \
  libdiamond_server.a \
  libdiamond_common.a \
  libdiamond_cli.a \
  libdiamond_util.a \
  univalue/libdiamond_univalue.a \
  crypto/libdiamond_crypto.a
if ENABLE_WALLET
DIAMOND_INCLUDES += $(BDB_CPPFLAGS)
noinst_LIBRARIES += libdiamond_wallet.a
endif

bin_PROGRAMS =
TESTS =

if BUILD_DIAMONDD
  bin_PROGRAMS += diamondd
endif

if BUILD_DIAMOND_UTILS
  bin_PROGRAMS += diamond-cli diamond-tx
endif

.PHONY: FORCE
# diamond core #
DIAMOND_CORE_H = \
  addrman.h \
  alert.h \
  allocators.h \
  amount.h \
  base58.h \
  bloom.h \
  chain.h \
  chainparams.h \
  chainparamsbase.h \
  chainparamsseeds.h \
  checkpoints.h \
  checkqueue.h \
  clientversion.h \
  coincontrol.h \
  coins.h \
  compat.h \
  core.h \
  core_io.h \
  crypter.h \
  db.h \
  hash.h \
  init.h \
  key.h \
  keystore.h \
  leveldbwrapper.h \
  limitedmap.h \
  main.h \
  miner.h \
  mruset.h \
  netbase.h \
  net.h \
  noui.h \
  pow.h \
  protocol.h \
  random.h \
  rpcclient.h \
  rpcprotocol.h \
  rpcserver.h \
  script/compressor.h \
  script/interpreter.h \
  script/script.h \
  script/sigcache.h \
  script/sign.h \
  script/standard.h \
  serialize.h \
  sync.h \
  threadsafety.h \
  timedata.h \
  tinyformat.h \
  txdb.h \
  txmempool.h \
  ui_interface.h \
  uint256.h \
  util.h \
  utilstrencodings.h \
  utilmoneystr.h \
  utiltime.h \
  version.h \
  wallet.h \
  wallet_ismine.h \
  walletdb.h \
  compat/sanity.h

JSON_H = \
  json/json_spirit.h \
  json/json_spirit_error_position.h \
  json/json_spirit_reader.h \
  json/json_spirit_reader_template.h \
  json/json_spirit_stream_reader.h \
  json/json_spirit_utils.h \
  json/json_spirit_value.h \
  json/json_spirit_writer.h \
  json/json_spirit_writer_template.h

obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh $(abs_top_builddir)/src/obj/build.h \
	  $(abs_top_srcdir)
libdiamond_util_a-version.$(OBJEXT): obj/build.h

# server: shared between diamondd and diamond-qt
libdiamond_server_a_CPPFLAGS = $(DIAMOND_INCLUDES) $(MINIUPNPC_CPPFLAGS)
libdiamond_server_a_SOURCES = \
  addrman.cpp \
  alert.cpp \
  bloom.cpp \
  chain.cpp \
  checkpoints.cpp \
  init.cpp \
  leveldbwrapper.cpp \
  main.cpp \
  miner.cpp \
  net.cpp \
  noui.cpp \
  pow.cpp \
  rpcblockchain.cpp \
  rpcmining.cpp \
  rpcmisc.cpp \
  rpcnet.cpp \
  rpcrawtransaction.cpp \
  rpcserver.cpp \
  timedata.cpp \
  txdb.cpp \
  txmempool.cpp \
  $(JSON_H) \
  $(DIAMOND_CORE_H)

# wallet: shared between diamondd and diamond-qt, but only linked
# when wallet enabled
libdiamond_wallet_a_CPPFLAGS = $(DIAMOND_INCLUDES)
libdiamond_wallet_a_SOURCES = \
  db.cpp \
  crypter.cpp \
  rpcdump.cpp \
  rpcwallet.cpp \
  wallet.cpp \
  wallet_ismine.cpp \
  walletdb.cpp \
  $(DIAMOND_CORE_H)

# crypto primitives library
crypto_libdiamond_crypto_a_CPPFLAGS = $(DIAMOND_CONFIG_INCLUDES)
crypto_libdiamond_crypto_a_SOURCES = \
  crypto/sha1.cpp \
  crypto/sha2.cpp \
  crypto/ripemd160.cpp \
  crypto/common.h \
  crypto/sha2.h \
  crypto/sha1.h \
  crypto/ripemd160.h

# univalue JSON library
univalue_libdiamond_univalue_a_SOURCES = \
  univalue/univalue.cpp \
  univalue/univalue_read.cpp \
  univalue/univalue_write.cpp \
  univalue/univalue_escapes.h \
  univalue/univalue.h

# common: shared between diamondd, and diamond-qt and non-server tools
libdiamond_common_a_CPPFLAGS = $(DIAMOND_INCLUDES)
libdiamond_common_a_SOURCES = \
  allocators.cpp \
  base58.cpp \
  chainparams.cpp \
  coins.cpp \
  core.cpp \
  core_read.cpp \
  core_write.cpp \
  hash.cpp \
  key.cpp \
  keystore.cpp \
  netbase.cpp \
  protocol.cpp \
  script/compressor.cpp \
  script/interpreter.cpp \
  script/script.cpp \
  script/sigcache.cpp \
  script/sign.cpp \
  script/standard.cpp \
  $(DIAMOND_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
libdiamond_util_a_CPPFLAGS = $(DIAMOND_INCLUDES)
libdiamond_util_a_SOURCES = \
  compat/glibc_sanity.cpp \
  compat/glibcxx_sanity.cpp \
  chainparamsbase.cpp \
  random.cpp \
  rpcprotocol.cpp \
  sync.cpp \
  uint256.cpp \
  util.cpp \
  utilstrencodings.cpp \
  utilmoneystr.cpp \
  utiltime.cpp \
  version.cpp \
  $(DIAMOND_CORE_H)

if GLIBC_BACK_COMPAT
libdiamond_util_a_SOURCES += compat/glibc_compat.cpp
libdiamond_util_a_SOURCES += compat/glibcxx_compat.cpp
endif

# cli: shared between diamond-cli and diamond-qt
libdiamond_cli_a_CPPFLAGS = $(DIAMOND_INCLUDES)
libdiamond_cli_a_SOURCES = \
  rpcclient.cpp \
  $(DIAMOND_CORE_H)

nodist_libdiamond_util_a_SOURCES = $(srcdir)/obj/build.h
#

# diamondd binary #
diamondd_LDADD = \
  $(LIBDIAMOND_SERVER) \
  $(LIBDIAMOND_COMMON) \
  $(LIBDIAMOND_UNIVALUE) \
  $(LIBDIAMOND_UTIL) \
  $(LIBDIAMOND_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBMEMENV)

if USE_LIBSECP256K1
  diamondd_LDADD += secp256k1/libsecp256k1.la
endif

if ENABLE_WALLET
diamondd_LDADD += libdiamond_wallet.a
endif
diamondd_SOURCES = diamondd.cpp
#

if TARGET_WINDOWS
diamondd_SOURCES += diamondd-res.rc
endif

diamondd_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS)
diamondd_CPPFLAGS = $(DIAMOND_INCLUDES)
diamondd_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS)

# diamond-cli binary #
diamond_cli_LDADD = \
  $(LIBDIAMOND_CLI) \
  $(LIBDIAMOND_COMMON) \
  $(LIBDIAMOND_UTIL) \
  $(LIBDIAMOND_CRYPTO) \
  $(BOOST_LIBS) \
  $(SSL_LIBS) \
  $(CRYPTO_LIBS)

diamond_cli_SOURCES = \
  diamond-cli.cpp

if USE_LIBSECP256K1
  diamond_cli_LDADD += secp256k1/libsecp256k1.la
endif
diamond_cli_CPPFLAGS = $(DIAMOND_INCLUDES)
#

# diamond-tx binary #
diamond_tx_LDADD = \
  $(LIBDIAMOND_UNIVALUE) \
  $(LIBDIAMOND_COMMON) \
  $(LIBDIAMOND_UTIL) \
  $(LIBDIAMOND_CRYPTO)

if USE_LIBSECP256K1
  diamond_tx_LDADD += secp256k1/libsecp256k1.la
endif

  diamond_tx_LDADD += $(BOOST_LIBS) \
  $(SSL_LIBS) \
  $(CRYPTO_LIBS)
diamond_tx_SOURCES = diamond-tx.cpp
diamond_tx_CPPFLAGS = $(DIAMOND_INCLUDES)
#
diamond_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS)

if TARGET_WINDOWS
diamond_cli_SOURCES += diamond-cli-res.rc
endif
diamond_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS)

CLEANFILES = leveldb/libleveldb.a leveldb/libmemenv.a *.gcda *.gcno

DISTCLEANFILES = obj/build.h

EXTRA_DIST = leveldb secp256k1

clean-local:
	-$(MAKE) -C leveldb clean
	-$(MAKE) -C secp256k1 clean 2>/dev/null
	rm -f leveldb/*/*.gcno leveldb/helpers/memenv/*.gcno
	-rm -f config.h

.rc.o:
	@test -f $(WINDRES)
	$(AM_V_GEN) $(WINDRES) -i $< -o $@

.mm.o:
	$(AM_V_CXX) $(OBJCXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	  $(CPPFLAGS) $(AM_CXXFLAGS) $(QT_INCLUDES) $(CXXFLAGS)  -c -o $@ $<

%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(abspath $(<D) $<)

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif
